#include<Caculator.h>
int flag;
int main()
{
    flag = 0;
    SetConsoleOutputCP(65001);
    while (1) {
        printf("四则运算计算器的实现\n");
        printf("--------------------\n");
        char expression[100000];
        printf("请输入你要计算的表达式：");
        fgets(expression, sizeof(expression), stdin);
        /*for (int i = 0; i < strlen(expression); i++)
        {
            if (isValidCharacter(expression[i])==FALSE)
            {
                printf("存在无效字符，请重新输入！\n");
                flag = 1;
                break;
            }
        }
        if (flag)
        {
            continue;
        }*/
        char* expression2[100000];
        changeExpression(expression, expression2);
        int result = evaluateexpression(expression2);
        printf("中缀表达式为:%s\n", expression2);
        printf("计算的结果是:%d\n", result);
    }
}
int JudgePriority(char op)
{
    switch (op) {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    default:
        return 0;
    }
}
//int isValidCharacter(char ch) {
//    return isdigit(ch) || isOperator(ch) || ch == '(' || ch == ')';
//}

void initLinkStack(LinkStack* stack)
{
    stack->top = NULL;
    stack->count = 0;
}
bool isEmpty(LinkStack* stack)
{
    if (stack->top == NULL)
    {
        return true;
    }
    else {
        return false;
    }
}
char pop(LinkStack* stack)
{
    if (stack->top == NULL)
    {
       // printf("存在无效字符！\n");
        flag = 1;
    }
    else {
        char data = stack->top->data;
        StackNode* temp = stack->top;
        stack->top = stack->top->next;
        stack->count--;
        free(temp);
        return data;
    }
}
char getdata(LinkStack* stack)
{
    if (stack->top == NULL)
    {
        //printf("存在无效字符！\n");
        flag = 1;
    }
    else {
        return stack->top->data;
    }
}
void push(LinkStack* stack, char data)
{
    StackNode* Node = (StackNode*)malloc(sizeof(StackNode));
    Node->data = data;
    Node->next = stack->top;
    stack->top = Node;
    stack->count++;
}
void push2(LinkStack* stack, int data)
{
    StackNode* Node = (StackNode*)malloc(sizeof(StackNode));
    Node->data = data;
    Node->next = stack->top;
    stack->top = Node;
    stack->count++;
}
char* changeExpression(char* expression,char* expression2)
{
    LinkStack* stack;
    stack = (LinkStack*)malloc(sizeof(LinkStack));
    initLinkStack(stack);
    int len = strlen(expression);
    int j = 0;
    for (int i = 0; i < len; i++) {
        char ch = expression[i];
        if ('0'<=ch&&ch<='9') {
            expression2[j++] = ch;
        }
        else if (('0' <= ch && ch <= '9') && ('0' <= expression[i + 1] && expression[i + 1] <= '9') && ((i + 1) < len))
        {
            expression2[j++] = ((ch - '0') * 10 + (expression[i + 1]-'0'))+'0';
        }
        else if (ch == '(') {
            push(stack, ch);
        }
        else if (ch == ')') {
            while (getdata(stack) != '(') {
                expression2[j++] = pop(stack);
            }
            pop(stack); // 弹出 '('
        }
        else if (isOperator(ch)) {
            while (!isEmpty(stack) && JudgePriority(getdata(stack)) >= JudgePriority(ch)) {
                expression2[j++] = pop(stack);
            }
            push(stack, ch);
        }
    }

    while (!isEmpty(stack)) {
        expression2[j++] = pop(stack);
    }

    expression2[j] = '\0';
}
int evaluateexpression(char* expression)
{
    LinkStack* stack;
    stack = (LinkStack*)malloc(sizeof(LinkStack));
    initLinkStack(stack);
    for (int i = 0; i < strlen(expression); i++) {
        char ch = expression[i];
        if ('0' <= ch && ch <= '9') {
            push2(stack, ch - '0'); // 将字符转换为数字
        }
        else { // 符号
            int a2 = pop(stack);
            int a1 = pop(stack);
            switch (ch) {
            case '+':
                push2(stack, a1 + a2);
                break;
            case '-':
                push2(stack, a1 - a2);
                break;
            case '*':
                push2(stack, a1 * a2);
                break;
            case '/':
                push2(stack, a1 / a2);
                break;
            }
        }
    }
    return pop(stack);
}
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}
