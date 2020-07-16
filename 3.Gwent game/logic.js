
let numberArray, numbersOfClicks, clickedElements, totalClicks, correctClicks;



init();

function init() {

    correctClicks = 0;
    totalClicks = 0;
    numbersOfClicks = 0;
    clickedElements = [];

    numberArray = [1, 2, 3, 4, 5, 6, 1, 2, 3, 4, 5, 6];
    numberArray.sort(function (a, b) { return Math.random() * 2 - 1 });
    
    document.getElementById('score').innerHTML = 0;
     document.getElementById('firstText').textContent = "Here is the Gwint Game! Click card below and find pairs";
    document.getElementById('header').textContent = "Gwent memory Test";
    
    for (let i = 0; i < 12; i++) {
        document.getElementById(i).src = "img/karta.png";
        document.getElementById(i).style.visibility = "visible";
    }
}

(function () {

    var arrayOfCards = document.getElementsByClassName("card");
    for (var i = 0; i < arrayOfCards.length; i++) {
        arrayOfCards[i].addEventListener('click', clickedElement);
    }
    document.getElementById("gameButton").addEventListener("click", init);
})();

function clickedElement() {

   document.getElementById(this.id).src = ("img/" + numberArray[this.id] + "Gwent.png");  
    
    numbersOfClicks++; 
    clickedElements.push(this.id);
    
    if (numbersOfClicks % 2 == 0) {
        checkCard();  
        totalClicks++;
        document.getElementById('score').innerHTML = totalClicks;
    }
}

function checkCard() {

    let delayTime = 1000;
    let One = document.getElementById(clickedElements[numbersOfClicks - 2]);
    let Two = document.getElementById(clickedElements[numbersOfClicks - 1]);

   // console.log("Cliced id " + One.id + " and id " + Two.id);

    if (One.id !== Two.id && One.src === Two.src) {
        correctClicks++
        setTimeout(function () {

            console.log("hidding cards");
            One.style.visibility = "hidden";
            Two.style.visibility = "hidden";
            if (correctClicks == 6) {
        document.getElementById('firstText').textContent = "Click button below and try again.";
        document.getElementById('header').textContent = "Great Job! You won!";
    }
        }, delayTime);
    }
    else {
        setTimeout(function () { 

         //  console.log("Wrong cards")
           One.src = "img/karta.png";
            Two.src = "img/karta.png";

        }, delayTime);
    }
    console.log(correctClicks);
    

}
