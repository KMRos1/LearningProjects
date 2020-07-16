
var dice, dice2, current, score1, score2, isPlayerOne, endGame;
endGame = false;


function playGame(){
	
	isPlayerOne=true;
	dice=dice2=0;
	current=0;
	score1=0;
	score2=0;

	document.getElementById('current-0').innerHTML = 0;
	document.getElementById('current-1').innerHTML = 0;
	document.getElementById('score-0').innerHTML = score1;
	document.getElementById('score-1').innerHTML = score2;
	document.getElementById("points").value = 100;

	document.querySelector('.player-1-panel').classList.remove('active');
	document.querySelector('.player-1-panel').classList.remove('winner');
	document.getElementById('name-0').innerHTML = 'Player1';
	
	document.querySelector('.player-0-panel').classList.add('active');
	document.querySelector('.player-0-panel').classList.remove('winner');
	document.getElementById('name-1').innerHTML = 'Player2';

	document.getElementById("roll").addEventListener("click", rollDice);
	document.getElementById("hold").addEventListener("click", hold);
	document.getElementById("newGame").addEventListener("click", playGame);
}

function rollDice(){
	
	dice = Math.floor(Math.random() * (6) + 1); 
	dice2 = Math.floor(Math.random() * (6) + 1); 


	changeImage();
	current+=(dice+dice2);

	if(isPlayerOne)	document.getElementById('current-0').innerHTML=current;
	else document.getElementById('current-1').innerHTML=current;

	badRolls();
}

function hold(){

if(isPlayerOne){

	score1+=current;
	document.getElementById('score-0').innerHTML=score1;
	current=0;
	document.getElementById('current-0').innerHTML=current;

	checkWin();	

		if (!endGame) {
			nextPlayer();
		}
}
else {
	score2+=current;
	document.getElementById('score-1').innerHTML=score2;
	current=0;
	document.getElementById('current-1').innerHTML=current;

	var isGameEnded =checkWin();

	isPlayerOne=!isPlayerOne;

		if (!endGame) {
		document.querySelector('.player-1-panel').classList.remove('active');
		document.querySelector('.player-0-panel').classList.add('active');
		}
}
}

function changeImage() {
	switch (dice) {
		case 1:
		document.getElementById('image').src='dice-1.png';
		break;

		case 2:
		document.getElementById('image').src='dice-2.png';
		break;

		case 3:
		document.getElementById('image').src='dice-3.png';
		break;

		case 4:
		document.getElementById('image').src='dice-4.png';
		break;

		case 5:
		document.getElementById('image').src='dice-5.png';
		break;

		case 6:
		document.getElementById('image').src='dice-6.png';
	}

	switch (dice2) {
		case 1:
			document.getElementById('image2').src = 'dice-1.png';
			break;

		case 2:
			document.getElementById('image2').src = 'dice-2.png';
			break;

		case 3:
			document.getElementById('image2').src = 'dice-3.png';
			break;

		case 4:
			document.getElementById('image2').src = 'dice-4.png';
			break;

		case 5:
			document.getElementById('image2').src = 'dice-5.png';
			break;

		case 6:
			document.getElementById('image2').src = 'dice-6.png';
	}
}

function checkWin(){

	if (isPlayerOne && score1 >= document.getElementById("points").value ) {

		document.getElementById('name-0').innerHTML = 'Winner!';
		document.querySelector('.player-0-panel').classList.remove('active');
		document.querySelector('.player-0-panel').classList.add('winner');
		document.getElementById("roll").removeEventListener("click", rollDice);
		document.getElementById("hold").removeEventListener("click", hold);
		endGame=true;
	}
	
	else if (!isPlayerOne && score2 >= document.getElementById("points").value) {

		document.querySelector('.player-1-panel').classList.remove('active');
		document.querySelector('.player-1-panel').classList.add('winner');
		document.getElementById('name-1').innerHTML = 'Winner!';
		document.getElementById("roll").removeEventListener("click", rollDice);
		document.getElementById("hold").removeEventListener("click", hold);

		endGame=true;
	}

}

function badRolls() {

	if ((dice == 1 || dice2 == 1) && isPlayerOne) {
		current = 0;
		document.getElementById('current-0').innerHTML = current;
		nextPlayer();
	}
	else if ((dice == 1 || dice2 == 1) && !isPlayerOne) {
		current = 0;
		document.getElementById('current-1').innerHTML = current;
		nextPlayer();
	}
		
	else if (dice == 6 && dice2 == 6) {
		if (isPlayerOne) {
			score1 = 0;
			document.getElementById('score-0').innerHTML = score1;
			current = 0;
			document.getElementById('current-0').innerHTML = current;
			nextPlayer();
		}
		else {
			score2 = 0;
			document.getElementById('score-1').innerHTML = score2;
			current = 0;
			document.getElementById('current-1').innerHTML = current;
			nextPlayer();
        }
    }
	
}

function nextPlayer() {
	if (isPlayerOne) {
		document.querySelector('.player-0-panel').classList.remove('active');
		document.querySelector('.player-1-panel').classList.add('active');
	}
	else {
		document.querySelector('.player-1-panel').classList.remove('active');
		document.querySelector('.player-0-panel').classList.add('active');
	}
	isPlayerOne = !isPlayerOne;
}
