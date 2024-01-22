#include<iostream>
#include<limits>  // Include <limits> header for input validation
using namespace std;
char elements[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};  //structure
char row;
char column;
string n1,n2;                                        // no of players
char token='x';
bool gametie = false ;
void draw(){               //for user interface

    for(int i=0;i<3;i++){
        cout<<"   |   |   \n";                            //figure o/p //empty spacing
        cout<<" "<<elements[i][0]<<" | "<<elements[i][1]<<" | "<<elements[i][2]<<endl;
        if(i<2){
            cout<<"___|___|___\n";
        }else{
            cout<<"   |   |   \n";
        }
    }    
}

void input(){         //linking figure with elements 
    int digit;
    if(token=='x'){                  //x is for 1player  //0 is for other
        cout<<n1<<" please enter your digit:";cin>>digit;
    }else{
        cout<<n2<<" please enter your digit:";cin>>digit;
    }

    
    if (digit >= 1 && digit <= 9) {                //assign values and space elements
        row = (digit - 1) / 3;
        column = (digit - 1) % 3;
        }else {
        cout << "Invalid input! Please enter a number between 1 and 9." << endl;
            cin.clear();            // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard invalid input
        }
    

    if(token=='x' && elements[row][column]!='x' && elements[row][column]!='0' ){
        elements[row][column]='x';              //to find any empty space to play
        token='0';
    }else if(token=='0' && elements[row][column]!='x' && elements[row][column]!='0'){ 
        elements[row][column]='0';
        token='x';
    }else{
        cout<<"No space !!!"<<endl;
        input();
    }
    draw();
}

bool logic(){                   
    for(int i=0;i<3;i++){  //i=3 because a player can win if elements are in vertical,horiz,diagonal
        if(elements[i][0] == elements[i][1] && elements[i][0]==elements[i][2] || elements[0][i] == elements[1][i] && elements[0][i]==elements[2][i] ){
            return true;                             //for verti,horiz
        }                          // conditions to win
    }
    if(elements[0][0]==elements[1][1] && elements[0][0]==elements[2][2] || elements[0][2]==elements[1][1] && elements[0][2]==elements[2][0]){
        return true;                                //for diagonal
    }

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){             // to check game is over or not
            if(elements[i][j] != 'x' && elements[i][j] != '0'){
                return false;
            }
        }
    }
    gametie =true;    // if 2 condition in this function are not meet then it is tie
    return true;
}

int main(){
    cout<<"Enter the first person name: ";cin>>n1;
    cout<<"Enter the second person name: ";cin>>n2;
    cout<<n1<<" is person1 so he/she will play first \n";
    cout<<n2<<" is person2 so he/she will play second \n";

    while(!logic()){
        draw();
        input();
        logic();       
    }

    if(token=='x' && gametie==false){
        cout<<n2<<" is the winner";
    }else if(token=='0' && gametie==false){
        cout<<n1<<" is the winner";
    }else{
        cout<<"draw";
    }
    
    return 0;
}