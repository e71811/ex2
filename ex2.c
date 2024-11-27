/******************
Name: ilay helfgot
ID: 212398648
Assignment: ex2
*******************/

#include <stdio.h>
#include <stdlib.h>

int main() {
	// 1 == true so i use that for an infinite while loop to keep running the menu until 7 is pressed
	int endProgram = 1;
	int key;

	while (endProgram) {
		printf("Choose an option:\n");
		printf("\t1. Happy Face\n");
		printf("\t2. Balanced Number\n");
		printf("\t3. Generous Number\n");
		printf("\t4. Circle Of Joy\n");
		printf("\t5. Happy Numbers\n");
		printf("\t6. Festival Of Laughter\n");
		printf("\t7. Exit\n");
		scanf("%d", &key);
		//i keep the menu running until the user chooses an available option
		if (key < 1 || key > 7) {
			printf("This option is not available, please try again.\n");
		}
		switch (key) {
			case 1: {
				char eye;
				char nose;
				char mouth;
				int size;
				int rememberSize;
				printf("Enter symbols for the eyes, nose, and mouth:\n");
				// here i get from the use what chars he want to represent each face segment
				scanf(" %c %c %c", &eye, &nose, &mouth);
				printf("Enter face size:\n");
				scanf("%d", &size);
				// here i check if the user inpu is an odd and positvie number
				while (size <= 0 || size % 2 == 0) {
					printf("The face's size must be an odd and positive number, please try again:\n");
					scanf("%d", &size);
				}
				//i am gonna use size and change it so i want to save its value
				rememberSize = size;
				printf("%c", eye);
				// space until the desired index
				while (size > 0) {
					printf(" ");
					size--;
				}
				printf("%c\n", eye);
				// after i changed size i would like to use it again so i define it to its original
				size = rememberSize;
					// here i want to calculate the position where the nose should be
				size = (size / 2 + 1);
				// here i make the spaces so the nose will be in the right position
				while (size > 0) {
					printf(" ");
					size--;
				}
				size = rememberSize;
				printf("%c\n", nose);

				// Print mouth
				printf("\\");
				while (size > 0) {
					printf("%c", mouth);
					size--;
				}

				printf("/\n");
				break;
			}

			case 2: {
				int number;
				int rememberNumber;
				int sumRight = 0;
				int count = 1;
				int sumLeft = 0;
				int totalSum = 0;
				int middleSum = 0;
				printf("Enter a number:\n");
				scanf("%d", &number);
				rememberNumber = number;

				// i check if the user typed positive number
				while (number <= 0) {
					printf("Only positive number is allowed, please try again:\n");
					scanf("%d", &number);
					rememberNumber = number;
				}

				// doing number/10 until !=0 will check for me if i looped until i checked all the numbers
				while (number / 10 != 0) {
					number = number / 10;
					count++;
				}
				// after i made changes to number i wanna use its original value so i define it to be the original
				number = rememberNumber;

				// %2 is checking if the number is odd or even
				if (count % 2 != 0) {
					// Sum the right side of the digits and by doing %10 i seperate the rightmost number
					for (int i = count; i > (count / 2) + 1; i--) {
						sumRight = sumRight + number % 10;
						number = number / 10;
					}
					number = rememberNumber;

					// Sum all digits in the number
					for (int i = 0; i < count; i++) {
						totalSum = totalSum + number % 10;
						number = number / 10;
					}
					number = rememberNumber;
					/*Sum the left side of the digits by starting to calculate from the sum of the right side with
					 the middle number and then reducing it so get the left side
					*/
					for (int i = count; i >= (count / 2) + 1; i--) {
						middleSum = middleSum + number % 10;
						number = number / 10;
					}
					sumLeft = totalSum - middleSum;

					// i check if the number is balanced
					if (sumLeft == sumRight) {
						printf("This number is balanced and brings harmony!\n");
					} else {
						printf("This number isn't balanced and destroys harmony.\n");
					}
					break;
				}
				number = rememberNumber;

				 /* this is same like the above code but in the case that the number is even
				 * i use again the % 10 to seperate the rightmost number and /10 to get the other number
				 * exepct the rightmost number and calculate the sum of the right side
				 */
				if (count % 2 == 0) {
					for (int i = count; i > count / 2; i--) {
						sumRight = sumRight + number % 10;
						number = number / 10;
					}
					number = rememberNumber;
					// Sum all digits in the number
					for (int i = 0; i < count; i++) {
						totalSum = totalSum + number % 10;
						number = number / 10;
					}
					sumLeft = totalSum - sumRight;

					// Check balance for even number of digits
					if (sumRight == sumLeft) {
						printf("This number is balanced and brings harmony!\n");
					} else {
						printf("This number isn't balanced and destroys harmony.\n");
					}
					break;
				}
				break;
			}

			case 3: {
				int number;
				int totalSum = 0;
				printf("Enter a number:\n");
				scanf("%d", &number);
				// i check if the input is <=0
				while (number <= 0) {
					printf("Only positive number is allowed, please try again:\n");
					scanf("%d", &number);
				}
				//here i check if number is dividable by i (which is all the number until number ) add those to totalSum
				for (int i = 1; i < number; i++) {
					if (number % i == 0) {
						totalSum = totalSum + i;
					}
				}
				if (number > totalSum) {
					printf("This number does not share.\n");
				} else {
					printf("This number is generous!\n");
				}
				break;
			}

		case 4: {
					int number;
					int primeNumber;
					int reversal = 0;
					int finished = 1;
					printf("Enter a number:\n");
					scanf("%d", &primeNumber);
					// i will change prime number multiple times so i want to save it
					int saver = primeNumber;
					// Check if the number is positive
					while (primeNumber <= 0) {
						printf("Only positive number is allowed, please try again:\n");
						scanf("%d", &primeNumber);
					}

					// here i use %10 and /10 to seperate the rightmost number everytime so i can then reverse the number
					while (primeNumber != 0) {
						number = primeNumber % 10;
						primeNumber = primeNumber / 10;
						reversal = reversal * 10 + number;
					}
					primeNumber = saver;
					// i use isPrime as an indicator that the number is or isnt a prime number
					int isPrime = 1;
					int i;
					// Prime check for the number
					for (i = 2; i <= primeNumber / 2; i++) {
						if (primeNumber % i == 0) {
							// if  isPrime = 0 it means its not a prime number
							isPrime = 0;
							break;
						}
					}

					// Prime check for the reversed number
					int isReversedPrime = 1;
					for (i = 2; i <= reversal / 2; i++) {
						if (reversal % i == 0) {
							// if  isPrime = 0 it means its not a prime number
							isReversedPrime = 0;
							break;
						}
					}

					// if one of the numbers arent prime print - "The circle remains incomplete."
					if (isPrime == 0 || isReversedPrime == 0) {
						printf("The circle remains incomplete.\n");
						finished = 0;
					}

					// if both of them are prime number print "This number completes the circle of joy!"
					if (finished == 1) {
						printf("This number completes the circle of joy!\n");
					}
					break;
		}
			case 5: {
				int number, newNumber, temp;
				int loop = 1, power = 0;
				printf("Enter a number:\n");
				scanf("%d", &number);
                 // i check if the user input is a positive number if not tell him to give us other input
				while (number <= 0) {
					printf("Only positive number is allowed, please try again:\n");
					scanf("%d", &number);
				}

				temp = loop;
				printf("Between 1 and %d only these numbers bring happiness:", number);

				while (loop <= number) {
					//i calculate here the power sum of digits for the number the user gave me
					while (temp != 0) {
						// newNumber = rightmost number of temp
						newNumber = temp % 10;
						power = power + (newNumber * newNumber);
						// removing the last digit from temp
						temp = temp / 10;
					}
                    // i check if the calculated power equals 1
					if (power == 1) {
						printf(" %d", loop);
						// move to the next number in the sequence
						loop++;
						temp = loop;
						power = 0;
					} else {
						// if power reaches 4 it means that this number is not happy so we skip to the next one
						if (power == 4) {
							loop++;
							temp = loop;
							power = 0;
						} else {
							temp = power;
							power = 0;
						}
					}
				}
				printf("\n");
				break;
			}

		case 6: {
					int max = 0;
					int x ;
					int smileNum;
					int cheerNum;
					//here i define stoploop to be 1 because 1 == true to the system and i want the while loop to run until it get breaked
					int stopLoop = 1;
					printf("Enter a smile and cheer number:\n");
					// clear the buffer from unwanted left chars values
					scanf("%*[^\n]");
					scanf("%*c");
					// in this loop i i want to keep getting input from the user if the terms arent me like the numbers need to be positive and etc
					while(stopLoop) {
						x = scanf("smile: %d, cheer: %d",&smileNum,&cheerNum);
                        // if scanf got 2 variables and the numbers are positive and arent equal
						if (x == 2 && cheerNum > 0 && smileNum > 0 && smileNum != cheerNum) {
							break;
						}
						printf("Only 2 different positive numbers in the given format are allowed for the festival, please try again:\n");
						// again i clear the buffer from unwanted left chars values
						scanf("%*[^\n]");
						scanf("%*c");
					}
					// here i get the max number from the user
					printf("Enter maximum number for the festival:\n");
					scanf("%d",&max);
					// i want to check if max is positive
					while (max<0) {
						printf("Only positive maximum number is allowed, please try again:\n");
						scanf(" %d",&max);
					}
					// here i go through 1 to max and check each number if its festival ,smile,cheer.
					for (int i=1;i<=max;i++) {
						if(i%smileNum==0 && i%cheerNum==0) {
							printf("Festival!\n");
						}else if(i%smileNum==0) {
							printf("Smile!\n");

						}else if(i%cheerNum==0) {
							printf("Cheer!\n");
						}else
							printf("%d\n",i);
					}
				break;
			}

			case 7: {
				// End the program - close the menu
				endProgram = 0;
				break;
			}
		}
	}
	printf("Thank you for your journey through Numeria!");
	return 0;
}
