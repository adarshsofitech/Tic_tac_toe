#include <iostream>
using namespace std;

// Board of 3x3 written in 1-d form
char board[9] = {'0','1','2','3','4','5','6','7','8'};

// Function to check the board if any of the two player has one
int win_checker()
{
		if (board[0] == board[1]  && board[1] == board[2] )
		{	if ( board[0] == '@' )			
			return 1;
			else
			return 2; 
		}		
		else if (board[3] == board[4]  && board[4] == board[5] )
			{	if ( board[3] == '@' )			
			return 1;
			else
			return 2; 
		}
		else if (board[6] == board[7]  && board[7] == board[8] )
			{	if ( board[6] == '@' )			
			return 1;
			else
			return 2; 
		}
		else if (board[0] == board[3]  && board[3] == board[6] )
			{	if ( board[0] == '@' )			
			return 1;
			else
			return 2; 
		}
		else if (board[1] == board[4]  && board[4] == board[7] )
			{	if ( board[1] == '@' )			
			return 1;
			else
			return 2; 
		}
	    else if (board[2] == board[5]  && board[5] == board[8] )
			{	if ( board[2] == '@' )			
			return 1;
			else
			return 2; 
		}
        else if (board[0] == board[4]  && board[4] == board[8] )
			{	if ( board[0] == '@' )			
			return 1;
			else
			return 2; 
		}
	    else if (board[2] == board[4]  && board[4] == board[6] )
			{	if ( board[2] == '@' )			
			return 1;
			else
			return 2; 
		}
	    else if (board[0] == board[3]  && board[3] == board[6] )
			{	if ( board[0] == '@' )			
			return 1;
			else
			return 2; 
		}
	    else 
		
        return 0;
        
}
//mark_board function to mark the board after taking input
char mark_board(int player, int box)
{
	if (player == 1 )
	{
        if(board[box]!='@'&& board[box]!='#')
        {
            board[box] = '@';
            return 'Y';
        }
        else 
        return 'N';
	}
	else
    {
        if(board[box]!='@' && board[box]!='#')
        {
            board[box] = '#';
            return 'Y';
        }
        else return 'N';
    }   
}

//Show_board to show current board after taking input 
void show_board()
{
    system("cls");
		for(int i=0;i<9;i++)
		{
			cout<< board[i] << "\t" ;
				if (i == 2 || i== 5 || i==8)
					cout<<"\n"; 
        }
}
int main()
{       system("cls");
		int player1 = 1, player2 =2 ;
		string name1,name2;
        cout<<"Enter player 1 name : ";
        cin>>name1;
        cout<<endl<<"Enter player 2 name : ";
        cin>>name2;
		int box, result = 0, flag = 0;
		show_board();
		for(int i=1;i<5;i++)
	{

		cout<< "\n" <<name1 << " Enter the Box number where you want to tick ---> ";
		cin>> box;
        while(true)
        {
            char istrue = mark_board( player1, box);
            if(istrue=='Y')
            break;
            else
            {
                cout<<"\n Opps you entered the filled box"<<endl<<"Enter box again"<<endl;
                cin>>box;
            }
        }
		
		show_board();

		result =win_checker();	
		if (result == 1 )
		{	cout<<"\n Congratualtions! " << name1 << " You Won ";
			flag = 1;			
			break;
		}
		else
		if (result == 2 )
		{	cout<<"\n Congratualtions! " << name2 << " You Won ";
			flag = 1;			
			break;
		}

		cout<< "\n" << name2 << " Enter the Box number where you want to tick ---> ";
		cin>> box;
        while(true)
        {
            char istrue = mark_board( player2, box);
            if(istrue=='Y')
            break;
            else
            {
                cout<<"\n Opps you entered the filled box"<<endl<<"Enter box again"<<endl;
                cin>>box;
            }
        }
		show_board();
		
		result =win_checker();	
		if (result == 1 )
		{	cout<<"\n Congratualtions! " << name1 << " You Won ";
			flag = 1;
			break;
		}
		else
		if (result == 2 )
		{	cout<<"\n Congratualtions! " << name2 << " You Won ";
			flag = 1;
			break;
		}
}
		if (flag == 0 )
		cout<<" \n The game is a draw ";
	
	return 0;
}
