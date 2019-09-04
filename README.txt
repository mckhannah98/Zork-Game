My game allows the user to teleport, move in different directions, use a map, displays the character's health and stamina
and also implements a quiz as the winning/losing condition.

The character's health and stamina is set to 100 each which are both depleted to 0 if the game is lost or remain at 100 if
the game is won.

To activate the quiz, the player must manually choose to walk into the quiz room. They can't access the quiz if they teleport
into the quiz room by chance.

The quiz contains 3 fairly simple questions, with the answer key being {A, B, C}. In order to win the game, the player must
answer all 3 questions correctly. If a single question is answered incorrectly, the player is then locked in the room and
all buttons are disabled and you get a game over message.

If a player answers all questions correctly, the game is won and they get a game winning message. The player can then choose to
explore the rest of the rooms or to exit the quiz room and re-enter the quiz room if they wish to play the quiz again or simply
exit the game.

I implemented a disable button feature in the directional buttons. If an exit isn't available, that button is disabled and can't
be pressed. For example, in room F, the only available exits are west, south and east. There's no north exit so the north button
is disabled.

The teleport function teleports the player into a random room throughout the map.

The map function displays the rooms and their available exits.

The quiz buttons for answering questions in the quiz are disabled until the player enters the quiz room themselves and disabled
once again when the game is either won or disabled along with everything else once the game is lost.
