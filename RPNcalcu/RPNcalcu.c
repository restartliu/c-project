#include"stack.h"

#define ifNumber(countString) ((countString >=48 && countString <= 57 || countString == '.') ? 1 : 0)
#define ifSignal(countString) ((countString=='+' || countString=='-' || countString=='*' || countString=='/')  ? 1 : 0)
#define ifEnd(countString) ((countString == '\0') ? 1 : 0)
#define ifBrackets(countString) ((countString == '(' || countString == ')') ? 1 : 0)
#define signalPriority(countString) ( !(countString=='+' || countString=='-') && (countString=='*' || countString=='/') ? 1 : 0 )
#define NumberLen 10
#define Signal 0.1234

double dealCount(STACKINFO* postFixList, STACKINFO* operStack);
void dealString(STACKINFO* operStack, STACKINFO* postFixList, char* countString);
char* dealNumber(char* countString, STACKINFO* postFixList);
char* dealSignal(char* countString, STACKINFO* operStack, STACKINFO* postFixList);
char* dealBrackets(char* countString, STACKINFO* operStack, STACKINFO* postFixList);
double count(double left, double right, char stackSignal);
double strtoi(char*);
void printTest(STACKINFO* postFixList);

int main()
{
	STACKINFO *operStack = stackinit();
	STACKINFO *postFixList = stackinit();
	
	char* countString = (char*)malloc(128 * (sizeof(char)));
	memset(countString, '\0', 128);
	scanf("%s", countString);

	dealString(operStack, postFixList, countString);
	postFixList->head = reverse(postFixList->head, NULL);
	printf("%lf\n", dealCount(postFixList, operStack));
	
	return 0;
}

double dealCount(STACKINFO* postFixList, STACKINFO* operStack)
{
	while (postFixList->head)
	{
		push(operStack, pop(postFixList));
		if (operStack->head && ifSignal((char)(operStack->head->receive - Signal)))
			push(operStack, count(pop(operStack), pop(operStack), (char)(pop(operStack) - Signal)));
	}
	return pop(operStack);
}

void dealString(STACKINFO* operStack, STACKINFO* postFixList, char* countString)
{
	while (!ifEnd(*countString))
	{
		if (ifNumber(*countString))
			countString = dealNumber(countString, postFixList);
		if (ifSignal(*countString))
			countString = dealSignal(countString, operStack, postFixList);
		if (ifBrackets(*countString))
			countString = dealBrackets(countString, operStack, postFixList);
	}
	while (operStack->head)
		push(postFixList, pop(operStack));
}

char* dealNumber(char *countString, STACKINFO *postFixList)
{
	char charNumber[NumberLen] = {'\0'};
	for (int i = 0; ifNumber(*countString); i++)
		charNumber[i] = *(countString++);
	if ( !ifEnd(charNumber[0]) )
		push(postFixList, strtoi(charNumber));
	return countString;
}

char* dealSignal(char* countString, STACKINFO* operStack, STACKINFO* postFixList)
{
	while ( operStack->head && signalPriority(*countString) <= signalPriority((char)(operStack->head->receive - Signal)) && !ifBrackets((char)(operStack->head->receive - Signal)) )
		push(postFixList, pop(operStack));
	push(operStack, *countString + Signal);
	return ++countString;
}

char* dealBrackets(char* countString, STACKINFO* operStack, STACKINFO* postFixList)
{
	push(operStack, ((*countString++) + Signal));
	while ( !ifBrackets(*countString) )
	{
		if (ifNumber(*countString))
			countString = dealNumber(countString, postFixList);
		if (ifSignal(*countString))
			countString = dealSignal(countString, operStack, postFixList);
	}
	while (!ifBrackets((char)(operStack->head->receive - Signal)))
		push(postFixList, pop(operStack));
	pop(operStack);
	return ++countString;
}

double count(double left, double right, char stackSignal)
{
	switch((char)stackSignal)
	{
		case '+':return (left+right);
		case '-':return (left-right);
		case '*':return (left*right);
		case '/':return (left/right);
	}
}

double strtoi(char* fch_addr)
{
	double number = 0;
	sscanf(fch_addr, "%lf", &number);
	return number;
}

void printTest(STACKINFO* postFixList)
{
	STACK* temp = postFixList->head;
	while (temp)
	{
		printf("%lf\n", temp->receive);
		temp = temp->next;
	}
}