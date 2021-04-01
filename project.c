  
#include <stdio.h> //Mengimpor file stdio.h

//fungsi perpangkatan
float pangkat(int i, int l)
{
    if(l==0){
        return 1;                  
    }
    else
        return i * pangkat(i,l-1);  
}
//vektor jarak a kuadrat + b kuadrat

int vektor(int o, int p, int q, int r)
{
    return (pangkat(p-o,2) + pangkat(r-q,2));
}

void findPos(char *dir)
{
    int up = 0, down = 0;
    int left = 0, right = 0;
    int i;
    int x;
    int y;
    time_t t;
    int a;
    int b;

    int robothealth = 100;
    int kecoakhealth = 100;
    int choice;
    int hit,miss;
    
    switch(choice)
    {
        case 1:
        printf("Enter the Direction String:  ");
        scanf("%s", &dir);    
    
    for (i = 0; dir[i] != '\0' ; i++) 
    {

        //Counts each direction
        if (dir[i] == 'U' || dir[i] == 'u')
            up++;
        else if (dir[i] == 'D' || dir[i] == 'd')
            down++;
        else if (dir[i] == 'L' || dir[i] == 'l')
            left++;
        else if (dir[i] == 'R' || dir[i] == 'r')
            right++;

          //In case of illegal character in the string
        else
        {
            printf("Position Unable to Find, Enter Correct Direction.");
            break;
        }
    }

    //Final position of robot
    x = right - left;
    y = up - down;
    printf("Final Position of the Robot: (");
    printf("%d", (x));
    printf(",%d", (y));
    printf(")");
    
    /* Intializes random number generator */

    srand((unsigned) time(&t));

    /* Print 2 random numbers from 0 to 100 */
    a = rand() % 100;
    b = rand() % 100;
    printf("\nPosisi kecoak adalah: ");
    printf("(%d,", a);
    printf("%d)", b);
   
    printf("\nJarak robot dengan kecoak");
    printf("\nJarak horizontal : %d", a-x);
    printf("\nJarak vertikal: %d", b-y);
    break;
           
    // The accuracy of robot firing
           case 2:
            if(vektor(a-x,right - left ,b-y,up - down) <= pangkat(3,2)){
                hit += 1;
                kecoakhealth -= 5;
                }
            else
                miss += 1;
            break;

           case 3:
           exit(1);
           break;
           
    if(hit >= 20 & kecoakhealth <= 0|| robothealth> 0)
    {
        printf("Mission Complete\n");
    }
    else if (robothealth == 0 || choice == 3)
    {
        printf("Game Over\n");
    }
    }
}

int main()
{
    char *dir;

    //Input the direction string 
    printf("Enter the Direction String:  ");
    scanf("%s", &dir);

    //Function call to calculate position
    findPos(&dir);

    return 0;
}
