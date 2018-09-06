#include <iostream>
#include <windows.h>

using namespace std;

class box
{

private:
    char _box[50][50],name1,name2;
    string player1, player2;
    int boxsize,u_boxsize,totalpoint,player1_point,player2_point,end_point;

public:

    box()//creates a box or asterisks
    {
        for(int i=0; i<20; i++)
        {
            if(i%2==0)
            {
                for(int j=0; j<20; j++)
                {
                    if(j%2==0)
                        _box[i][j] = '+';
                    else
                        _box[i][j] = ' ';
                }
            }
            else
            {
                for(int j=0; j<20; j++)
                {
                    _box[i][j] = ' ';
                }
            }
        }
        _box[0][0] = '*';
        totalpoint=0;
        player1_point=0;
        player2_point=0;
        end_point=0;
    }
    //All functions are here
    void cutname();
    void takeinfo();
    void instruction();
    //void showinfo();
    void printbox(int playernumber,int flag);
    int movepoint(int playernumber);
    int checkforbox(int playernumber);
    int finishgame();
    void showresult();
    void debug();
};

void box::instruction()//Game instruction function that how to play
{
    cout<<"\t\t\t\t\t ******************Developed by******************\n"<<endl;
    cout<<"\t\t\t\t\t\tFahmida Noor & Kamruzzaman leeon"<<endl;
    cout<<"\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<"\n\n\t\t\t\t\t\t\tGAME INSTRUCTIONS"<<endl;
    cout<<"\t\t\t\t\t\t--------------------------------"<<endl;
    cout<<"\t\t\t\t\t\t|\tControl keys are:      |"<<endl;
    cout<<"\t\t\t\t\t\t|\t1) Up (w/W)            |"<<endl;
    cout<<"\t\t\t\t\t\t|\t2) Down (s/S)          |"<<endl;
    cout<<"\t\t\t\t\t\t|\t3) Left (a/A)          |"<<endl;
    cout<<"\t\t\t\t\t\t|\t4) Right (d/D)         |"<<endl;
    cout<<"\t\t\t\t\t\t|\t5) Select (e/E)        |"<<endl;
    cout<<"\t\t\t\t\t\t--------------------------------\n\n"<<endl;
}

void box::showresult()//Show Result function will give us a final result of both players
{
    system("cls");
    cout<<"\n\n\tPoint : "<<endl;
    cout<<"\t\t"<<player1<<" : "<<player1_point<<"\t"<<player2<<" : "<<player2_point<<"\n\n\n"<<endl;
    if(player1_point>player2_point)
        cout << "\t\t "<<player1<<" has won the game\n\n\n"<<endl;
    else if(player1_point<player2_point)
        cout << "\t\t "<<player2<<" has won the game\n\n\n"<<endl;
    else
        cout<< "\t\t IT's a Draw\n\n\n"<<endl;
}

void box::debug()//using debug function we can show that
{
                    //how many end point and increasing of total point
    cout<<end_point<<endl;
    cout<<totalpoint<<endl;
}

int box::finishgame()//Finish game checks that whether
{
                        //end points and total points are equal or not
    if(end_point == totalpoint)
    {
        system("cls");
        for(int i=0; i<boxsize; i++)
        {
            for(int j=0; j<boxsize; j++)
            {
                cout << _box[i][j];
            }
            cout << endl;
        }
        showresult();
        cout << "\n\nPress ENTER to exit.......\n\n\n";
        cin.get();//It is used for take enter from keyboard
        exit(1);
    }
}

void box::cutname()//Cut name function for picking a letter from a big string Name
{
    name1 = player1.at(0);
    name2 = player2.at(0);
    cout<<name1<< " " <<name2<<endl;
}

void box::takeinfo()//Players information function
{
again:
    cout << "Player Name(1st) : ";
    cin >>player1;
    cout << "Player Name(2nd) : ";
    cin >>player2;
    cout << "Enter Box size(2-10) : ";
    cin >>u_boxsize;//User input a box size
    if(u_boxsize<2||u_boxsize>10)
    {
        system("cls");
        cout << "\nInvalid Entry\n\n";
        cin.get();
        goto again;
    }
    boxsize = u_boxsize+(u_boxsize-1);//It's a whole box size of both seen and unseen asterisks
    end_point = (u_boxsize-1)*(u_boxsize-1);
}

//void box::showinfo()
//{
//    cout << "Player Name(1st) : ";
//    cout << player1;
//    cout << "Player Name(2nd) : ";
//    cout << player2;
//    cout << "Box Size : ";
//    cout << boxsize-1;
//}

void box::printbox(int playernumber,int flag)//we use Print box function for printing asterisk for our game
{
    checkforbox(playernumber);

    if(playernumber==0 && flag==0)
    {
        cout <<"Current turn "<<player1<<" \n\n"<<endl;
    }
    else if(playernumber==1 && flag==0)
    {
        cout <<"Current turn "<<player2<<" \n\n"<<endl;
    }

    for(int i=0; i<boxsize; i++)
    {
        for(int j=0; j<boxsize; j++)
        {
            cout << _box[i][j];
        }
        cout << endl;
    }
    cout<<"\n\nPoint : "<<endl;
    cout<<player1<<" : "<<player1_point<<"\t"<<player2<<" : "<<player2_point<<endl;
    cout<<"\nPress H/h for read game instruction"<<endl;

}

int box::checkforbox(int playernumber)//Check box function checks that
{
    //whether it's(box) around portion is filled up or not
    for(int i=1; i<boxsize; i=i+2)
    {
        for(int j=1; j<boxsize; j=j+2)
        {
            if(_box[i][j]==name1||_box[i][j]==name2)
            {
                continue;
            }
            else
            {
                if(_box[i][j-1]=='|'&&_box[i+1][j]=='-'&&_box[i][j+1]=='|'&&_box[i-1][j]=='-')
                {
                    totalpoint++;
                    if(playernumber==0)
                    {
                        _box[i][j]=name1;
                        player1_point++;
                        finishgame();
                        movepoint(playernumber);
                    }
                    else if(playernumber==1)
                    {
                        _box[i][j]=name2;
                        player2_point++;
                        finishgame();
                        movepoint(playernumber);
                    }
                }
            }
        }
    }
}

int check(int up, int left, int u_size)//Check function check boxes left, right, up and down portion
{
    if(up < 0 || up >= u_size)
        return -1;

    else if( left <0 || left >= u_size)
        return -1;

    else
        return 1;

}

int box::movepoint(int playernumber)//We use Move function for game control
{
c:
    int flag=0;
    int up=0,left=0;
    int i=0,j=0;
    int u_size = u_boxsize;
    int trueOrfalse;
    char _move='k',_select='k';
    _box[0][0] = '*';
    printbox(playernumber,flag);

    while(_move != 'e' || _move != 'E')
    {
        cout << "\n1st move : ";
        cin >> _move;
        if(_move == 'w' || _move == 'W')
        {
            up--;
            trueOrfalse = check(up,left,u_size);
            if(trueOrfalse == -1)
            {
                up++;
                system("cls");
                printbox(playernumber,flag);
                cout << "\nInvalid move" <<endl;
            }
            else
            {
                _box[i][j] = '+';
                i = i-2;
                _box[i][j] = '*';
                system("cls");
                printbox(playernumber,flag);
            }
        }
        else if(_move == 's' || _move == 'S')
        {
            up++;
            trueOrfalse = check(up,left,u_size);
            if(trueOrfalse == -1)
            {
                up--;
                system("cls");
                printbox(playernumber,flag);
                cout << "\nInvalid move" <<endl;
            }
            else
            {
                _box[i][j] = '+';
                i = i+2;
                _box[i][j] = '*';
                system("cls");
                printbox(playernumber,flag);
            }
        }
        else if(_move == 'A' || _move == 'a')
        {
            left--;
            trueOrfalse = check(up,left,u_size);
            if(trueOrfalse == -1)
            {
                left++;
                system("cls");
                printbox(playernumber,flag);
                cout << "\nInvalid move" <<endl;
            }
            else
            {
                _box[i][j] = '+';
                j = j-2;
                _box[i][j] = '*';
                system("cls");
                printbox(playernumber,flag);
            }
        }
        else if(_move == 'D' || _move == 'd')
        {
            left++;
            trueOrfalse = check(up,left,u_size);
            if(trueOrfalse == -1)
            {
                left--;
                system("cls");
                printbox(playernumber,flag);
                cout << "\nInvalid move" <<endl;
            }
            else
            {
                _box[i][j] = '+';
                j = j+2;
                _box[i][j] = '*';
                system("cls");
                printbox(playernumber,flag);
            }
        }
        else if(_move=='E' ||_move=='e')
        {
            system("cls");
            printbox(playernumber,flag);
            cout << "\nPoint Selected" <<endl;
            break;
        }
        else if(_move=='H' ||_move=='h')
        {
            system("cls");
            instruction();
        }

        else
        {
            cout << "\nInvalid move\n" <<endl;
        }
    }

    int re_i,re_j;
    re_i = i;
    re_j = j;
b:
    cout << "2nd move : ";
    cin >> _move;
    if(_move=='s' || _move=='S')
    {
        up++;
        trueOrfalse = check(up,left,u_size);
        if(trueOrfalse == -1)
        {
            up++;
            system("cls");
            printbox(playernumber,flag);
            cout << "\nInvalid move" <<endl;
            goto b;
        }
        else
        {
            _box[i][j] = '+';
            i = i+1;
            if(_box[i][j]=='|')
            {
                system("cls");
                cout<<"Already connected\n"<<endl;
                goto c;
            }
            else
            {
                _box[i][j] = '|';
                system("cls");
                printbox(playernumber,flag);
            }
        }
    }
    else if(_move=='w' || _move=='W')
    {
        up--;
        trueOrfalse = check(up,left,u_size);
        if(trueOrfalse == -1)
        {
            up++;
            system("cls");
            printbox(playernumber,flag);
            cout << "\nInvalid move" <<endl;
            goto b;
        }
        else
        {
            _box[i][j] = '+';
            i = i-1;

            if(_box[i][j]=='|')
            {
                system("cls");
                cout<<"Already connected\n"<<endl;
                goto c;
            }
            else
            {
                _box[i][j] = '|';
                system("cls");
                printbox(playernumber,flag);
            }
        }
    }
    else if(_move=='a' || _move=='A')
    {
        left--;
        trueOrfalse = check(up,left,u_size);
        if(trueOrfalse == -1)
        {
            left++;
            system("cls");
            printbox(playernumber,flag);
            cout << "\nInvalid move" <<endl;
            goto b;
        }
        else
        {
            _box[i][j] = '+';
            j = j-1;

            if(_box[i][j]=='-')
            {
                system("cls");
                cout<<"Already connected\n"<<endl;
                goto c;
            }
            else
            {
                _box[i][j] = '-';
                system("cls");
                printbox(playernumber,flag);
            }
        }
    }
    else if(_move=='d' || _move=='D')
    {
        left++;
        trueOrfalse = check(up,left,u_size);
        if(trueOrfalse == -1)
        {
            left--;
            system("cls");
            printbox(playernumber,flag);
            cout << "\nInvalid move" <<endl;
            goto b;
        }

        else
        {
            _box[i][j] = '+';
            j = j+1;
            if(_box[i][j]=='-')
            {
                system("cls");
                cout<<"Already connected\n"<<endl;
                goto c;
            }
            else
            {
                _box[i][j] = '-';
                system("cls");
                printbox(playernumber,flag);
            }
        }
    }
    else if(_move=='H' ||_move=='h')
    {
        system("cls");
        instruction();
    }

    else
    {
        system("cls");
        printbox(playernumber,flag);
        cout<<"\nInvalid move"<<endl;
        goto b;
    }

    flag++;

    return flag;
}

int main()//Our's game will start from here
{
    box b1;
    char a;
    int endgame;
    int playernumber = 0;
    b1.instruction();
    b1.takeinfo();
    b1.cutname();

    while(1)
    {
        endgame=b1.finishgame();

        if(playernumber==0)
        {
            system("cls");
            b1.movepoint(playernumber);
            playernumber=1;
            if(endgame==-1)
            {
                break;
            }
        }
        else if(playernumber==1)
        {
            system("cls");
            b1.movepoint(playernumber);
            playernumber=0;
            if(endgame==-1)
            {
                break;
            }
        }
    }
    b1.showresult();

    return 0;
}
