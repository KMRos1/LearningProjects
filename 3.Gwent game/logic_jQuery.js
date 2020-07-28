let numberArray, numbersOfClicks, clickedElements, totalClicks, correctClicks;

init();

function init() {

    correctClicks = 0;
    totalClicks = 0;
    numbersOfClicks = 0;
    clickedElements = [];

    numberArray = [1, 2, 3, 4, 5, 6, 1, 2, 3, 4, 5, 6];
    numberArray.sort(function (a, b) { return Math.random() * 2 - 1 });
    
    $('#score').text('0');
    $('#firstText').text("Here is the Gwint Game! Click card below and find pairs");
    $('#header').text("Gwent memory Test");

    $('.card').attr('src', "img/karta.png");
    $('.card').css('visibility', 'visible');
   
}

(function () {

    $('.card').click(clickedElement)
    $("#gameButton").click(init);

})();

function clickedElement() {

  $(`#${this.id}`).attr('src', `img/${numberArray[this.id]}Gwent.png`);  
    
    numbersOfClicks++; 
    clickedElements.push(this.id);
    
    if (numbersOfClicks % 2 == 0) {
        checkCard();  
        totalClicks++;
        $('#score').text(totalClicks);
    }
}

function checkCard() {

    let delayTime = 1000;

    let One = $(`#${clickedElements[numbersOfClicks - 2]}`);
    let Two = $(`#${clickedElements[numbersOfClicks - 1]}`);

    if (One.attr('id') !== Two.attr('id') && One.attr('src') === Two.attr('src')) {

        correctClicks++

        setTimeout(function () {

            One.css('visibility', 'hidden');
            Two.css('visibility', 'hidden');
           
            if (correctClicks == 6) {

               $('#firstText').text('Click button below and try again.');
               $('#header').text("Great Job! You won!");

    }
        }, delayTime);
    }
    else {
        setTimeout(function () { 

            One.attr('src','img/karta.png');
            Two.attr('src', 'img/karta.png');

        }, delayTime);
    }
}
