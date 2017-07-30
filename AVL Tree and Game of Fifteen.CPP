#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <dos.h>
#include <string.h>
#include <graphics.h>
#include <conio.h>
#include <iostream.h>
#include <io.h>
// constants
#define DIM_MIN 3
#define DIM_MAX 9
#define true 1
#define false 0

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
int move(int tile);
int won(void);
void create(void);
void boardInsert(int m,int n,int data);
int boardRet(int m,int n);

int mainmenu();
void AVL();
int GOF();


/* structure for col headnode */
struct cheadnode
{
    int colno ;
    struct node *down ;
    struct cheadnode *next ;
} *tempc, *col;

/* structure for row headnode */
struct rheadnode
{
    int rowno ;
    struct node * right ;
    struct rheadnode *next ;
} *tempr,*row;

/* structure for node to store element */
struct node
{
    int row ;
    int col ;
    char val ;
    struct node *right ;
    struct node *down ;
}   *tempn,*start,*previous ,*waste;

/* structure for special headnode */
struct spmat
{
    struct rheadnode *firstrow ;
    struct cheadnode *firstcol ;
    int noofrows ;
    int noofcols ;
} *head;

int win[DIM_MAX][DIM_MAX];
int d;
int i=0;
int j=0;



struct nodee
{
    int element;
    struct nodee *left;
    struct nodee *right;
}*root;

int gdriver=DETECT,gmode=0,errorcode;
char element[3];
int x=1,maxx,midx,xcoord,ycoord,level=320,prevlevel;
int max(int i,int j)
{
    if(i>=j) return i;
    else return j;
}




class avlTree
{
    public:
	void GDisplay(nodee* ,int , int);
	nodee* insert(nodee *, int );
	int height(nodee *);
	int diff(nodee *);
	nodee *RR(nodee *);
	nodee *LL(nodee *);
	nodee *LR(nodee *);
	nodee *RL(nodee *);
	nodee* balance(nodee *);
	void display(nodee *, int);
	void inorder(nodee *);
	void preorder(nodee *);
	void postorder(nodee *);
	avlTree()
	{
	    root = NULL;
	}
};
void graph()
{
  int maxy,maxx,midx,midy,choice;
	maxx=getmaxx();
	maxy=getmaxy();
	midx=maxx/2;
	midy=maxy/2;

  setcolor(LIGHTGREEN);

	//ADD delay
	for(int i=5;i<=midy-50;i=i+10)
	      {	outtextxy(0,i,"#");
		outtextxy(maxx-10,i,"#");
		//delay(10);
	       }
	for(i=5;i<=maxx;i=i+25)
	       {	outtextxy(i,0," $*$ ");

			outtextxy(i,midy-50," $*$ ");
			//delay(100);
	       }
	settextstyle(0,HORIZ_DIR,3);
	setcolor(YELLOW);
	outtextxy(midx-100,20,"AVL Tree");
	graphdefaults();
	setcolor(CYAN);
	outtextxy(70,100,"1. Insertion");
	outtextxy(250,100,"2. Display");
	outtextxy(420,100,"3. Inorder traversal");
	outtextxy(70,130,"4. Preorder traversal");
	outtextxy(280,130,"5. Postorder traversal");
	outtextxy(470,130,"6. Graphical Display");
	outtextxy(70,150,"7. Exit");
	outtextxy(85,170,"Enter your Choice: ");
	//gotoxy(midx,midy); cprintf("Enter your Choice: ");
       //	cprintxy(midx,midy,WHITE,"Enter your Choice:  ");
	for(i=1;i<=maxx;i=i+10)
		outtextxy(i,midy-50," - ");

}

void main()
{

    int choice;
	choice=mainmenu();
	cout<<choice;
	switch(choice)
	{
	    case 1: AVL();
		    break;
	    case 2: GOF();
	    break;
    }



	closegraph();
	getch();
}

int mainmenu()
{
	 int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

	int maxy,maxx,midx,midy,choice;
	maxx=getmaxx();
	maxy=getmaxy();
	midx=maxx/2;
	midy=maxy/2;
	cleardevice();
	int i;
	setcolor(LIGHTGREEN);

	//ADD delay
	for(i=5;i<=maxy-25;i=i+7)
	      {	outtextxy(0,i,"*");
		outtextxy(maxx-10,i,"*");
		//delay(10);
	       }
	for(i=5;i<=maxx;i=i+25)
	       {	outtextxy(i,0,">**<");

			outtextxy(i,maxy-28,">**<");
			//delay(100);
	       }



		setfillstyle(XHATCH_FILL,BLUE);
		floodfill(midx-235,midy,LIGHTGREEN);
		settextstyle(10,HORIZ_DIR,4);
		setcolor(WHITE);
		outtextxy(midx-150,midy-200,"DS PROJECT");

		//line(midx-230,midy-75,midx+230,midy-75);
		setcolor(WHITE);
		//rectangle(midx-230,midy-75,midx+230,midy+150);
		//setfillstyle(SOLID_FILL,BLACK);
		//floodfill(midx-220,midy,BLACK);
		settextstyle(0,HORIZ_DIR,2);
		outtextxy(midx-230,midy-75,"Choose your option!!");
		outtextxy(midx-230,midy-35,"1)STUDY TIME - AVL TREE!");
		outtextxy(midx-230,midy,"2) FUN TIME - GAME OF FIFTEEN!");
		outtextxy(midx-230,midy+30,"Enter your Choice: ");
		cin>>choice;
		cleardevice();
		return choice;
		closegraph();
getch();


}


void AVL()
{
	 int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	int maxy,maxx,midx,midy,choice;
	maxx=getmaxx();
	maxy=getmaxy();
	midx=maxx/2;
	midy=maxy/2;

    clrscr();
    cleardevice();
    int c, z, xcoord, ycoord;
    avlTree avl;
    while (1)
    {
	clrscr();
	cleardevice();
	graph();

	gotoxy(midx,midy);
	cprintf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t");
	cin>>c;
	switch(c)
	{
	case 1:
	    cout<<"Enter Number to be inserted: ";
	    cin>>z;
	    root = avl.insert(root, z);
	    break;
	case 2:
	    if (root == NULL)
	    {
		cout<<"Tree is Empty"<<endl;
		continue;
	    }
	    cout<<"Balanced AVL Tree:"<<endl;
	    avl.display(root, 1);
	    getch();
	    break;
	case 3:
	    cout<<"Inorder Traversal:"<<endl;
	    avl.inorder(root);
	    cout<<endl;
	    getch();
	    break;
	case 4:
	    cout<<"Preorder Traversal:"<<endl;
	    avl.preorder(root);
	    cout<<endl;
	    getch();
	    break;
	case 5:
	    cout<<"Postorder Traversal:"<<endl;
	    avl.postorder(root);
	    cout<<endl;
	    getch();
	    break;
	case 6:

	   int errorcode = graphresult();


	    xcoord=midx/2;
	    ycoord=40;

	    if (errorcode != grOk)
	     {
	       printf("Graphics error: %s", grapherrormsg(errorcode));
	       printf("Press any key to stop");
	       getch();
	       exit(1);
	     }
	     cleardevice();
	     setbkcolor(LIGHTBLUE);
	     settextstyle(2,0,5);
	    avl.GDisplay(root,midx,50);
	     getch();
	     restorecrtmode();
	    break;

	case 7:
	    exit(0);
	    break;
	default:
	    cout<<"Wrong Choice"<<endl;
	}
    }

    closegraph();
    getch();

}

int avlTree::height(nodee *x)
{
    int h = 0;
    if (x!= NULL)
    {
	int lh = height (x->left);
	int rh = height (x->right);
	int maxh = max (lh, rh);
	h = maxh + 1;
    }
    return h;
}

int avlTree::diff(nodee *a)
{
    int lh = height (a->left);
    int rh = height (a->right);
    int bf= lh - rh;
    return bf;
}

nodee *avlTree::RR(nodee *x)
{
    nodee *y;
    y= x->right;
    x->right = y->left;
    y->left = x;
    return y;
}

nodee *avlTree::LL(nodee *x)
{
    nodee *y;
    y = x->left;
    x->left = y->right;
    y->right = x;
    return y;
}

nodee *avlTree::LR(nodee *x)
{
    nodee *y;
    y = x->left;
    x->left = RR (y);
    return LL (x);
}

nodee *avlTree::insert(nodee *root, int z)
{
    if (root == NULL)
    {
	root = new nodee;
	root->element = z;
	root->left = NULL;
	root->right = NULL;
	return root;
    }
    else if (z < root->element)
    {
	root->left = insert(root->left, z);
	root = balance (root);
    }
    else if (z >= root->element)
    {
	root->right = insert(root->right, z);
	root = balance (root);
    }
    return root;
}


void avlTree::display(nodee *ptr, int lvl)
{
    int i;
    if (ptr!=NULL)
    {
	display(ptr->right, lvl + 1);
	printf("\n");
	if (ptr == root)
	cout<<"Root -> ";
	for (i = 0; i < lvl && ptr != root; i++)
	    cout<<"        ";
	cout<<ptr->element;
	display(ptr->left, lvl + 1);
    }
}

void avlTree::inorder(nodee *ptr)
{
    if (ptr == NULL)
	return;
    inorder (ptr->left);
    cout<<ptr->element<<"  ";
    inorder (ptr->right);
}


void avlTree::preorder(nodee *ptr)
{
    if (ptr == NULL)
	return;
    cout<<ptr->element<<"  ";
    preorder (ptr->left);
    preorder (ptr->right);

}


void avlTree::postorder(nodee *ptr)
{
    if (ptr == NULL)
	return;
    postorder ( ptr ->left );
    postorder ( ptr ->right );
    cout<<ptr->element<<"  ";
}



nodee *avlTree::RL(nodee *x)
{
    nodee *y;
    y = x->right;
    x->right = LL (y);
    return RR (x);
}

nodee *avlTree::balance(nodee *y)
{
    int bf = diff (y);
    if (bf > 1)
    {
	if (diff (y->left) > 0)
	    y = LL (y);
	else
	    y = LR (y);
    }
    else if (bf < -1)
    {
	if (diff (y->right) > 0)
	    y = RL (y);
	else
	    y = RR (y);
    }
    return y;
}
void avlTree::GDisplay(nodee *p,int xcoord,int ycoord)
{
  if (p!=NULL)
    {
       level=level/2;
       setfillstyle(1,BROWN);
       setcolor(LIGHTGREEN);
       if(p->left->element!=NULL)
	line(xcoord,ycoord,xcoord-level,ycoord+50);
       if(p->right->element!=NULL)
	line(xcoord,ycoord,xcoord+level,ycoord+50);
       fillellipse(xcoord,ycoord,10,10);
       sprintf(element,"%d",p->element,xcoord,ycoord);
       settextstyle(2,0,4);
       setcolor(YELLOW);
       outtextxy(xcoord-7,ycoord-7,element);

       GDisplay(p->left,xcoord-(level),ycoord+50);
       GDisplay(p->right,xcoord+(level),ycoord+50);
       level=level*2;
    }
}


int GOF()
{
     // greet user with instructions
    greet();

    printf("Enter the size of board\n");
    scanf("%d",&d);
    head=(struct spmat*)malloc(sizeof(struct spmat));
    head->noofcols=d;
    head->noofrows=d;
    if (d < DIM_MIN || d > DIM_MAX)
    {
	printf("Board must be between %i x %i and %i x %i, inclusive.\n",
	    DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
	return 2;
    }

    // open log
    FILE* file = fopen("log.txt", "w");
    if (file == NULL)
    {
	return 3;
    }


    //create the board using multi- linklist
    create();

    // initialize the board
    init();

    // accept moves until game is won

    while(true)
    {
	// clear the screen
	clear();

	// draw the current state of the board
	draw();

	 // log the current state of the board (for testing)
	for (i = 0; i < d; i++)
	{
	    for (j = 0; j < d; j++)
	    {
		fprintf(file, "%i", boardRet(i,j));
		if (j < d - 1)
		{
		    fprintf(file, "|");
		}
	    }
	    fprintf(file, "\n");
	}
	fflush(file);

	// check for win
	if (won())
	{
	    printf("You Win!!!\n");
	    break;
	}

	// prompt for move
	printf("Tile to move: ");

	int tile;
	scanf("%d",&tile);

	// quit if user inputs 0 (for testing)
	if (tile == 0)
	{
	    break;
	}

	// log move (for testing)
	fprintf(file, "%i\n", tile);
	fflush(file);

	// move if possible, else report illegality
	if (!move(tile))
	{
	    printf("\nIllegal move.\n");
	    delay(50);
	}



	  // sleep thread for animation's sake
	delay(50);
    }

    // close log
    fclose(file);

    // success
    return 0;
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    delay(20);
}

/** Creates multi linklist

*/
void create(void)
{

    for(i=1;i<=d;i++)
    {
	if(i==1)
	{
	    tempc=(struct cheadnode*)malloc(sizeof(struct cheadnode));
	      tempc->colno=i;
	      head->firstcol=tempc;

	}
	else {
		tempc->next=(struct cheadnode*)malloc(sizeof(struct cheadnode));
		tempc=tempc->next;
	}

	tempc->next=NULL;
	tempc->colno=i;
    }

    for(i=1;i<=d;i++)
    {
	if(i==1)
	{
	    tempr=(struct rheadnode*)malloc(sizeof(struct rheadnode));
	      tempr->rowno=i;
	      head->firstrow=tempr;

	}
	else {tempr->next=(struct rheadnode*)malloc(sizeof(struct rheadnode));
		tempr=tempr->next;}
	tempr->next=NULL;
	tempr->rowno=i;
    }
}

/** Assigns new value to the
    respective node given by m(row) and n(column)
 **/
void boardInsert(int m, int n , int data)
{
    m=m+1;
    n=n+1;
    tempr=head->firstrow;
    tempr=head->firstrow;
    while(tempr->rowno!=m)
    {
	tempr=tempr->next;
    }

    tempn=tempr->right;

    while(tempn->col!=n)
    {tempn=tempn->right;
    }
    tempn->val=data;

}

/** Returns value of node given by m(row) and column n(column)
**/
int boardRet(int m, int n)
{
    m=m+1;
    n=n+1;
    tempr=head->firstrow;

    while(tempr->rowno!=m)
    {
	tempr=tempr->next;
    }

    tempn=tempr->right;

    while(tempn->col!=n)
    {tempn=tempn->right;
    }
    return tempn->val;

}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    system("cls");
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).
 */
void init()
{
    int s,temp;
    s=(d*d)-1;
    tempr=head->firstrow;
    tempc=head->firstcol;
    for(i=1;i<=d;i++)
    {
	for(j=1;j<=d;j++)
	{

	    if( j==1 )
	    {
		tempn=(struct node*)malloc(sizeof(struct node));
		tempr->right=tempn;
		tempn->val=s;
		tempn->row=i;
		tempn->col=j;
		tempn->right=NULL;
		tempn->down=NULL;
		//printf ( "Row: %d Col: %d Val: %d\n", tempn -> row, tempn -> col,tempn -> val ) ;
		tempr=tempr->next;
	    }
	    else
	    {
		tempn->right=(struct node*)malloc(sizeof(struct node));
		tempn=tempn->right;
		//printf("Enter Element::");
		//fflush(stdin);
		//scanf("%c",&e);
		tempn->val=s;
		tempn->row=i;
		tempn->col=j;
		tempn->right=NULL;
		tempn->down=NULL;
		//printf ( "Row: %d Col: %d Val: %d\n", tempn -> row, tempn -> col, tempn -> val ) ;
	    }
	    s=s-1;


	}
    }

       if(d%2==0)
    {
	temp=boardRet(d-1,d-2);
	boardInsert(d-1,d-2,boardRet(d-1,d-3));   // try swaping with 2 variables
	boardInsert(d-1,d-3,temp);
    }


}

/**
 * Prints the board in its current state.
 */
void draw(void)
{
    for(i=0;i<d;i++)
    {
	for(j=0;j<d;j++)
	{   int k=boardRet(i,j);
	    if(k==0)
	    {
		printf(" _");
		printf("\t");
	    }
	    else
	    {
		printf("%2d",k);
		printf("\t");
	    }
	}
	printf("\n");
    }
}

/**
 * Prints the board in its current state.
 */
int won(void)
{
      int s=1,a;
    a=d*d;
    for(i=0;i<d;i++)
    {
	for(j=0;j<d;j++)
	{
	    win[i][j]=s;
	    s=s+1;
	}
    }
    win[d-1][d-1]=0;
    int count;
    for(i=0;i<d;i++)
    {
	count=0;
	for(j=0;j<d;j++)
	{   int p=boardRet(i,j);
	    if(win[i][j]==p)
	    {
		count++;
	    }
	}
    }
    if(count==d)
    {
	return 1;
    }
    return 0;
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false.
 */
int move(int tile)
{

    int tposi,tposj,bposi,bposj,temp;  //t=tile,b=blank,pos=psition,i and j are variables
    for(i=0;i<d;i++)
    {
	for(j=0;j<d;j++)
	{   int p=boardRet(i,j);
	    if(p==tile)
	    {
		tposi=i;
		tposj=j;
	    }
	    if(p==0)
	    {
		bposi=i;
		bposj=j;
	    }

	    if((tposi+1)==bposi && bposj==tposj)    //above
	    {
		temp=boardRet(tposi,tposj);
		boardInsert(tposi,tposj,boardRet(bposi,bposj));
		boardInsert(bposi,bposj,temp);
		return 1;
	    }
	    else if(tposi==(bposi+1) && bposj==tposj)  //below
	    {
		temp=boardRet(tposi,tposj);
		boardInsert(tposi,tposj,boardRet(bposi,bposj));
		boardInsert(bposi,bposj,temp);
		return 1;
	    }
	    else if(tposi==bposi && bposj==(tposj+1))  //right
	    {
		temp=boardRet(tposi,tposj);
		boardInsert(tposi,tposj,boardRet(bposi,bposj));
		boardInsert(bposi,bposj,temp);
		return 1;
	    }
	    else if(tposi==bposi && (bposj+1)==tposj)  //left
	    {
		temp=boardRet(tposi,tposj);
		boardInsert(tposi,tposj,boardRet(bposi,bposj));
		boardInsert(bposi,bposj,temp);
		return 1;
	    }
	}
    }

    return 0;
}
