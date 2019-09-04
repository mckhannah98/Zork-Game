/* The custom event that I have implemented is a quiz.
 * This is activated by manually walking into the quiz room, teleporting into it won't activate the quiz.
 * This is because the player should choose to walk into the quiz room to activate it.
 * The game is won if all of the answers in the quiz are answered correctly and lost if a question is answered incorrectly.
 * When the game is lost, the UI is locked and you must exit the game.
 * When the game is won, you have the choice to continue exploring or replay the quiz if you return to the quiz room.
 * The answer key to the quiz is (A, B, C).
 */


#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Room.h"
#include <string>
#include <iostream>
#include <sstream>
#include <ctime>

using namespace std;

vector<Room*> listOfRooms;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    createRooms();
    printWelcome();
    directionalButtons();
    srand(time(0));
    setQuizButtonsToInactive();
    getHealth();
    getStamina();


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createRooms()
{
    Room *a, *b, *c, *d, *e, *f, *g, *h, *i, *j;

    a = new Room("a");
        a->addItem(new Item("x", 1, 11));
        a->addItem(new Item("y", 2, 22));
        listOfRooms.push_back(a);
    b = new Room("b");
        b->addItem(new Item("xx", 3, 33));
        b->addItem(new Item("yy", 4, 44));
        listOfRooms.push_back(b);
    c = new Room("c");
        listOfRooms.push_back(c);
    d = new Room("d");
        listOfRooms.push_back(d);
    e = new Room("e");
        listOfRooms.push_back(e);
    f = new Room("f");
        listOfRooms.push_back(f);
    g = new Room("g");
        listOfRooms.push_back(g);
    h = new Room("Quiz Room");
        listOfRooms.push_back(h);
    i = new Room("i");
        listOfRooms.push_back(i);
    j = new Room("j");
        listOfRooms.push_back(j);



//             (N, E, S, W)
    a->setExits(f, b, d, c);
    b->setExits(NULL, NULL, NULL, a);
    c->setExits(NULL, a, NULL, NULL);
    d->setExits(a, e, NULL, i);
    e->setExits(NULL, NULL, NULL, d);
    f->setExits(NULL, g, a, h);
    g->setExits(NULL, NULL, NULL, f);
    h->setExits(NULL, f, NULL, NULL);
    i->setExits(NULL, d, NULL, j);
    j->setExits(NULL, i, NULL,NULL);

        currentRoom = a;
}

void MainWindow::printWelcome()
{
   // cout << currentRoom->longDescription() << endl;

    ui -> textEdit -> setText(QString::fromStdString("room = a. \nitems in room = x y\nexits = east north south west"));
}

void MainWindow::directionalButtons()
{
    string exits = currentRoom -> exitString();

    string::size_type Exit = exits.find("west", 0);
    if (Exit != string::npos)
    {
        ui -> pushButton -> setDisabled(false);
    }
    else
    {
        ui -> pushButton -> setDisabled(true);
    }

    Exit = exits.find("north", 0);
    if (Exit != string::npos)
    {
        ui -> pushButton_2 -> setDisabled(false);
    }
    else
    {
        ui -> pushButton_2 -> setDisabled(true);
    }

    Exit = exits.find("south", 0);
    if (Exit != string::npos)
    {
        ui -> pushButton_3 -> setDisabled(false);
    }
    else
    {
        ui -> pushButton_3 -> setDisabled(true);
    }

    Exit = exits.find("east", 0);
    if (Exit != string::npos)
    {
        ui -> pushButton_4 -> setDisabled(false);
    }
    else
    {
        ui -> pushButton_4 -> setDisabled(true);
    }
}

void MainWindow::goRoom(string command)
{
   // ui -> textEdit -> setText(QString::fromStdString(currentRoom->longDescription()));
    string direction = command;
    Room* nextRoom = currentRoom->nextRoom((direction));

    currentRoom = nextRoom;
    ui -> textEdit -> setText(QString::fromStdString(currentRoom->longDescription()));
    directionalButtons();

    if (nextRoom == NULL)
    {
        ui -> textEdit -> setText (QString::fromStdString ("There is no room in this direction."));
    }

    else
    {
        currentRoom = nextRoom;

        if (currentRoom -> shortDescription() == "Quiz Room")
        {
            setQuizButtonsToActive();
            Quiz();
            directionalButtons();
        }

        else
        {
            ui -> textEdit -> setText(QString::fromStdString( currentRoom -> longDescription()));
            directionalButtons();
        }
    }

}

string MainWindow::go(string direction)
{
    Room* nextRoom = currentRoom->nextRoom(direction);

    if (nextRoom == NULL)
    {
        return ("direction null");
    }

    else
    {
        currentRoom = nextRoom;
        return currentRoom ->longDescription();
    }
}

void MainWindow::goTeleport()
{
    int RandIndex = rand() % listOfRooms.size();
    currentRoom = listOfRooms[RandIndex];
    ui -> textEdit -> setText(QString::fromStdString(currentRoom->longDescription()));

    string exits = currentRoom -> exitString();

    string::size_type Exit = exits.find("west", 0);
    if (Exit != string::npos)
    {
        ui -> pushButton -> setDisabled(false);
    }
    else
    {
        ui -> pushButton -> setDisabled(true);
    }

    Exit = exits.find("north", 0);
    if (Exit != string::npos)
    {
        ui -> pushButton_2 -> setDisabled(false);
    }
    else
    {
        ui -> pushButton_2 -> setDisabled(true);
    }

    Exit = exits.find("south", 0);
    if (Exit != string::npos)
    {
        ui -> pushButton_3 -> setDisabled(false);
    }
    else
    {
        ui -> pushButton_3 -> setDisabled(true);
    }

    Exit = exits.find("east", 0);
    if (Exit != string::npos)
    {
        ui -> pushButton_4 -> setDisabled(false);
    }
    else
    {
        ui -> pushButton_4 -> setDisabled(true);
    }
}

void MainWindow::on_pushButton_clicked()
{
    goRoom(("west"));
}

void MainWindow::on_pushButton_2_clicked()
{
    goRoom(("north"));
}

void MainWindow::on_pushButton_3_clicked()
{
    goRoom(("south"));
}

void MainWindow::on_pushButton_4_clicked()
{
    goRoom(("east"));
}

void MainWindow::on_pushButton_5_clicked()
{
    goTeleport();
}

void MainWindow::Quiz()
{
    string question1;
    question1 = "Welcome to the quiz. To win this game, you must answer all questions correctly. Fail a question, and you've lost the game\n\nWhich module code is Event Driven Programming?\n\nA) CS4076\nB) CS4815\nC) CS4115\nD) CS4006\n";

    ui -> textEdit_2 -> setText(QString::fromStdString (question1));

    setAnswer("A");
}

string MainWindow::getAnswer()
{
    return answer;
}

void MainWindow::setAnswer(string test)
{
    this -> answer = test;
}

void MainWindow::setQuizButtonsToInactive()
{
    ui -> pushButton_6 -> setEnabled(false);
    ui -> pushButton_7 -> setEnabled(false);
    ui -> pushButton_8 -> setEnabled(false);
    ui -> pushButton_9 -> setEnabled(false);
}

void MainWindow::setQuizButtonsToActive()
{
    ui -> pushButton_6 -> setEnabled(true);
    ui -> pushButton_7 -> setEnabled(true);
    ui -> pushButton_8 -> setEnabled(true);
    ui -> pushButton_9 -> setEnabled(true);
}

void MainWindow::on_pushButton_6_clicked()
{
    if (answer == "A")
    {
        ui -> textEdit_2 -> setText (QString::fromStdString ("What programming language is used in this module?\n\nA) Python\nB) C++\nC) Java\nD) Ruby\n"));
        setAnswer("B");
    }

    else
    {
        ui -> textEdit_2 -> setText (QString::fromStdString("That was an incorrect answer, as a result, you will now be locked in this room forever. Game Over!"));
        setEnabled(false);

        health = "0";
        stamina = "0";

        ui -> textEdit_4 -> setText (QString::fromStdString("Character's Health: " + health));
        ui -> textEdit_5 -> setText (QString::fromStdString("Character's Stamina: " + stamina));
    }
}

void MainWindow::on_pushButton_7_clicked()
{
    if (answer == "B")
    {
        ui -> textEdit_2 -> setText (QString::fromStdString("What was Minecraft originally programmed in?\n\nA) C\nB) C++\nC) Java\nD) Lua\n"));
        setAnswer("C");
    }

    else
    {
        ui -> textEdit_2 -> setText (QString::fromStdString("That was an incorrect answer, as a result, you will now be locked in this room forever. Game Over!"));
        setEnabled(false);

        health = "0";
        stamina = "0";

        ui -> textEdit_4 -> setText (QString::fromStdString("Character's Health: " + health));
        ui -> textEdit_5 -> setText (QString::fromStdString("Character's Stamina: " + stamina));
    }
}

void MainWindow::on_pushButton_8_clicked()
{
    if (answer == "C")
    {
        ui -> textEdit_2 -> setText (QString::fromStdString("You have answered all of the questions correctly and can now escape. Game Won!\n\n\n")
                                     + "|@@@@|     |####|\n"
                                     + "|@@@@|     |####|\n"
                                     + "|@@@@|     |####|\n"
                                     + "\\@@@@|     |####/\n"
                                     + "  \\@@@|       |###/\n"
                                     + "   `@@|_____|##'\n"
                                     + "               (O)\n"
                                     + "         .-'  '  '  '  '-.\n"
                                     + "     .'     *  *  *     `.\n"
                                     + "   :      *          *      :\n"
                                     + "  :   ~  F I R S T  ~   :\n"
                                     + "  :   ~  P L A C E  ~  :\n"
                                     + "   :      *          *      :\n"
                                     + "     `.    *  *  *     .'\n"
                                     + "        `- . . . . . -'");

        ui -> pushButton_6 -> setEnabled(false);
        ui -> pushButton_7 -> setEnabled(false);
        ui -> pushButton_8 -> setEnabled(false);
        ui -> pushButton_9 -> setEnabled(false);
    }

    else
    {
        ui -> textEdit_2 -> setText (QString::fromStdString("That was an incorrect answer, as a result, you will now be locked in this room forever. Game Over!"));
        setEnabled(false);

        health = "0";
        stamina = "0";

        ui -> textEdit_4 -> setText (QString::fromStdString("Character's Health: " + health));
        ui -> textEdit_5 -> setText (QString::fromStdString("Character's Stamina: " + stamina));
    }
}

void MainWindow::on_pushButton_9_clicked()
{
    ui -> textEdit_2 -> setText (QString::fromStdString("That was an incorrect answer, as a result, you will now be locked in this room forever. Game Over!"));

    setEnabled(false);

    health = "0";
    stamina = "0";

    ui -> textEdit_4 -> setText (QString::fromStdString("Character's Health: " + health));
    ui -> textEdit_5 -> setText (QString::fromStdString("Character's Stamina: " + stamina));

}

void MainWindow::on_pushButton_10_clicked()
{
    ui -> textEdit_3 -> setText (QString::fromStdString ("[Quiz Room] --- [f] --- [g]\n           ¦              ¦         ¦\n           ¦              ¦         ¦\n          [c]   ----  [a] --- [b]\n           ¦              ¦         ¦\n           ¦              ¦         ¦\n[j] --- [i]   ----   [d] --- [e]"));
}

int MainWindow::getHealth()
{
    ui -> textEdit_4 -> setText (QString::fromStdString("Character's Health: " + health));
}

int MainWindow::getStamina()
{
    ui -> textEdit_5 -> setText (QString::fromStdString("Character's Stamina: " + stamina));
}

/*void MainWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    ui -> listWidget -> takeItem (ui -> listWidget -> row(item));
    delete item;
}*/

/*void MainWindow::addItems (vector <Item> items)
{
    ui -> listWidget -> clear();

   //for (int i = 0; i < zork -> getCurrentRoom().numberOfItems(); i++)
   for (int i = 0; i < currentRoom->numberOfItems(); i++)
   {
       ui -> listWidget -> addItem (QString::fromStdString((items[i].getShortDescription)()));
   }
}*/

/*void MainWindow::on_pushButton_11_clicked()
{
    addItems(currentRoom->itemsInRoom);
}*/
