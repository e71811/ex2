/******************
Name: ilay helfgot
ID: 212398648
Assignment: ex2
*******************/

#include <stdio.h>
#include <stdlib.h>

int main() {
	//main menu
	int endProgram = 1 ;
	int key ;
	//i keep the menu running until the user chooses an available option
	while (endProgram) {
		printf("Choose an option:\n");
		printf("\t1. Happy Face\n");
		printf("\t2. Balanced Number\n");
		printf("\t3. Generous Number\n");
		printf("\t4. Circle Of Joy\n");
		printf("\t5. Happy Numbers\n");
		printf("\t6. Festival Of Laughter\n");
		printf("\t7. Exit\n");
		scanf("%d",&key);
		if (key < 1 || key > 7) {
			printf("This option is not available, please try again.\n");
		}
			switch (key) {
		    case 1: {
			char eye;
			char nose;
			char mouth;
			int size ;
			int rememberSize;
			printf("Enter symbols for the eyes, nose, and mouth:\n");
			scanf(" %c"" %c "" %c", &eye, &nose, &mouth);
			printf("Enter face size:\n");
			scanf("%d",&size);
			// before i make changes in size i want to be able to use it multiple times thats why i use remembersize == size
			rememberSize = size ;
			//i check if the user chooses negative number if so i tell the user to choose other number if hes typing positive number but an even on i also tell him to choose new number
			while( size <=0 || size%2 == 0 ) {
				printf("The face's size must be an odd and positive number, please try again:\n");
				scanf("%d",&size);
			}
			printf("%c",eye);
			//i want to make space until i get to the wished index
			while(size>0) {
				printf(" ");
				size--;
			}
			printf("%c\n",eye);
			// before i make changes in size i want to be able to use it multiple times thats why i use remembersize == size
			size=rememberSize;
			//here i want size to represent the amount of spaces i need to make until i print "nose "
			size= (size/2+1) ;
			while(size>0) {
				printf(" ");
				size--;

			}
			// before i make changes in size i want to be able to use it multiple times thats why i use remembersize == size
			size=rememberSize;
			printf("%c\n",nose);
			//i print the first mouth "piece"
			printf(	"\\");
			//here i print the user selected mouth "piece"
			while(size>0) {
				printf("%c",mouth);
				size--;
			}
			// here i print the last mouth "piece"
			printf(	"/\n");


			break;
		}

		case 2: {
			int number;
			int rememberNumber;
			int sumRight = 0;
			int count = 1;
			int sumLeft = 0 ;
			int totalSum = 0;
			int middleSum = 0 ;
			printf("Enter a number:\n");
			scanf(" %d",&number);
			rememberNumber = number;
			// here i want to count how many numbers there are in "number"
			while(number/10 !=0) {
				number=number/10 ;
				count++;
			}
			number=rememberNumber;
			//i check if count is an odd number ( i want to know if the user typed an even indexed number or odd )
			if(count%2!=0) {
				// i want to sum up all the numbers from right of the middle number in "number "
				for( int i = count; i > (count/2)+1; i-- ) {
					sumRight=sumRight+number%10;
					number = number/10;
				}
				number = rememberNumber;
				//i want to sum up all the numbers in "number"
				for( int i = 0; i <count; i++ ) {
					totalSum=totalSum+number%10;
					number = number/10;
				}
				number = rememberNumber;
				//i want here to count all the number on the right side including the middle one
				for( int i = count; i >= (count/2)+1; i-- ) {
					middleSum=middleSum+number%10;
					number = number/10;
				}
				// here i count the left side by calculating total sum - middlesum
				sumLeft=totalSum-middleSum;
				//i check if the right side in equal to the left side
				if (sumLeft == sumRight) {
					printf("This number is balanced and brings harmony!\n");
				}
				else {
					printf("This number isn't balanced and destroys harmony.\n");
				}

				break;
			}
			number = rememberNumber;
			//i check if count is an even number ( i want to know if the user typed an even indexed number or odd )
			if(count%2 ==0) {
				//here i want to sum up all the number that are in the right side of "number" number
				for( int i = count; i > count/2; i-- ) {
					sumRight=sumRight+number%10;
					number = number/10;
				}
				//after i changed "number" i want it to stay as it was
				number = rememberNumber;
				//here i sum up all the numbers of "number" so i would be able to calculate how much is the sum up of the left side
				for( int i = 0; i <count; i++ ) {
					totalSum=totalSum+number%10;
					number = number/10;

				}
				sumLeft=totalSum-sumRight;
				// here iam checking if the left sum up is equal to the right sum up
				if (sumRight == sumLeft) {
					printf("This number is balanced and brings harmony!\n");
				}else {
					printf("This number isn't balanced and destroys harmony.\n");
				}
				break;
			}
		}

		case 3: {
			int number;
			int totalSum = 0;
			int count =1;
			printf("Enter a number:\n");
			scanf("%d",&number);
			int rememberNumber= number;
			//i define it to be right number
			int rightNumber = number%10;
			while(number<0 ) {
				printf("Only positive number is allowed, please try again:\n");
				scanf("%d",&number);
			}
			if(number/10 !=0) {
				number=number/10;
				//here i count how many numbers there are in number after i removed the right one
				while(number/10 !=0) {
					number=number/10 ;
					count++;
				}
				//i summed up all the numbers in number after i removed the right one
				for( int i = 0; i <count; i++ ) {
					totalSum=totalSum+number%10;
					number = number/10;

				}
				if(rightNumber>totalSum) {
					printf("This number is generous!\n");
				}else {
					printf("This number does not share.\n");
				}
			}else {
				printf("This number does not share.\n");

			}
			break;
		}

		case 4: {
			int number;
			int primeNumber;
			int reversal=0;
			int finished =1 ;
			printf("Enter a number:\n");
			scanf("%d", &primeNumber);
			int saver =primeNumber;
			//i want to start from 2 because i dont want to check 1 in terms of dividing
			int i=2;
			//i want to start from 2 because i dont want to check 1 in terms of dividing
			int j=2;
			//here i check if the number is positive or not
			while(primeNumber<0) {
				printf("Only positive number is allowed, please try again:\n");
				scanf("%d",&primeNumber);
			}
			primeNumber=saver;
			// here i reverse the primeNumber by making everytime the right number * 10 ^(count"index") so it will be the in the left in "reversal"
			while(primeNumber !=0) {
				number=primeNumber%10;
				primeNumber=primeNumber/10;
				reversal=reversal*10+number;
			}
			primeNumber=saver;
			//here i check if from the number 2 until the number "primeNumner"  there is a number that after doing % between them = 0 also i do it for reversal
			// the goal here is to check if there is a number between 2 to the "primenumber" or "reversal" that we can multiplie  so it will get to these numbers
			while( i<primeNumber &&j<reversal) {
				if(primeNumber%i == 0||reversal%j == 0) {
					printf("The circle remains incomplete.\n");
					finished = 0 ;
					break;
				}
				i++;
				j++;
			}
			// here i want check if any of the number (prime number or his reversed form ) is not prime if they are both then it will print
			if(finished==1) {
				printf("This number completes the circle of joy!\n");
			}

			break;
		}
		case 5: {

		}
		case 6: {
			int max = 0;
			int x ;
			int smileNum;
			int cheerNum;
			printf("Enter a smile and cheer number:\n");
			scanf("%*[^\n]");
			scanf("%*c");
			// in this loop i i want to keep getting input from the user if the terms arent me like the numbers need to be positive and etc
			while(1) {
				x = scanf("smile: %d, cheer: %d",&smileNum,&cheerNum);

				if (x == 2 && cheerNum > 0 && smileNum > 0 && smileNum != cheerNum) {
					break;
				}
				printf("Only 2 different positive numbers in the given format are allowed for the festival, please try again:\n");
				scanf("%*[^\n]");
				scanf("%*c");
			}
			// here i get the max number from the user
			printf("Enter maximum number for the festival:\n");
			scanf("%d",&max);

			while (max<0) {
				printf("Only positive maximum number is allowed, please try again:\n");
				scanf(" %d",&max);

			}
			for (int i=1;i<=max;i++) {
				if(i%smileNum==0 && i%cheerNum==0) {
					printf("Festival!!\n");
				}else if(i%smileNum==0) {
					printf("smile!\n");

				}else if(i%cheerNum==0) {
					printf("cheer!\n");
				}else
					printf("%d\n",i);
			}
			break;
		}



			case 7: {
				printf("Thank you for your journey through Numeria!\n");
			    endProgram=0;
				break;
			}


		}

	}

		return 0;
	}












// Case 1: Draw Happy Face with given symbols for eyes, nose and mouse
/* Example:
* n = 3:
* 0   0
*   o
* \___/
*/


// Case 2: determine whether the sum of all digits to the left of the middle digit(s)
// and the sum of all digits to the right of the middle digit(s) are equal
/* Examples:
Balanced: 1533, 450810, 99
Not blanced: 1552, 34
Please notice: the number has to be bigger than 0.
*/

// Case 3: determine whether the sum of the proper divisors (od an integer) is greater than the number itself
/* Examples:
Abudant: 12, 20, 24
Not Abudant: 3, 7, 10
Please notice: the number has to be bigger than 0.
*/

// Case 4: determine wether a number is a prime.
/* Examples:
This one brings joy: 3, 5, 11
This one does not bring joy: 15, 8, 99
Please notice: the number has to be bigger than 0.
*/


// Happy numbers: Print all the happy numbers between 1 to the given number.
// Happy number is a number which eventually reaches 1 when replaced by the sum of the square of each digit
/* Examples:
Happy :) : 7, 10
Not Happy :( : 5, 9
Please notice: the number has to be bigger than 0.
*/

// Festival of Laughter: Prints all the numbers between 1 the given number:
// and replace with "Smile!" every number that divided by the given smile number
// and replace with "Cheer!" every number that divided by the given cheer number
// and replace with "Festival!" every number that divided by both of them
/* Example:
6, smile: 2, cheer: 3 : 1, Smile!, Cheer!, Smile!, 5, Festival!
*/