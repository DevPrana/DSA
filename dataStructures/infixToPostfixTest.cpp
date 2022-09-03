#include <iostream>
#include <string>

template <class T> class stack {
    public:
        int top;
        int size;
        T *stackArray;

        stack() {
            size = 100;
        }
        stack(int size) {            
            this -> size = size;
            top = -1;
            stackArray = (T*)( malloc( size * sizeof(T) ) );
        }; 
        

        int isEmpty() {
            if(top == -1) {
                return 1;
            }   
            else {
                return 0;
            };
        }

        int isFull() {
            if( ( (top) + 1) == (size) ) {
                return 1;
            }
            else {
                return 0;
            };
        }
        void stackPush (int element) {
            if ( isFull() ) {
            std::cout << "Stack overflow. Element not inserted.\n";
            }
            else {
                ( top )++;
                *(stackArray + top) = element;
            };
        };

        T stackPop () {
            if ( isEmpty() ) {
                std::cout << "Stack underflow. Stack is empty.\n";
                return -1;
            }
            (top )--;
            return ( *( stackArray + top + 1 ) );
        };

}; 

int precedOpCheck(char op) {
    switch(op) {
        case '^':
            return 4;
            break;
        case '/':
        case '*':
        case '%':
            return 3;
            break;
        case '+': 
        case '-':
            return 2;
            break;
        default:
            return 0; // This default case will help us verify whether a certain character is an operator or not.
            break;
    };    
};

std::string inToPost(std::string infix) {

    std::string postfix = "";
    int infixLength = infix.length();

    stack<char> opStack(50);
    char current;
    
    for(int index = 0; index < infixLength ; index++) {
        current = infix[index];
        
        if(current == '(') {
            opStack.stackPush(current);
        }
        else if(current == ')') {
            while((opStack.stackArray)[opStack.top] != '(') {
                postfix += opStack.stackPop();
            }
            opStack.stackPop();
        }
        else if( precedOpCheck(current) ) {
            if( precedOpCheck(*( (opStack.stackArray) + (opStack.top) )) < precedOpCheck(current) ) {
                opStack.stackPush(current);
            }
            else {
                while( precedOpCheck( *( (opStack.stackArray) + (opStack.top) ) ) >= precedOpCheck(current) ) {
                    postfix += opStack.stackPop();
                };
                opStack.stackPush(current);

            };
        }
        else if( ( (65 <= (int)(current)) && (90 >= (int)(current)) ) || ( (97 <= (int)(current)) && (122 >= (int)(current)) )) {
            postfix += current;
        };
    }

    return postfix;
}

int main() {
    //* Test Expression
    std::string infix = "(K + L - M*N + (O^P) * W/U/V * T + Q)";
    
    //? Expected Output : KL+MN∗−OP^W∗U/V/T∗+Q+

    std::string postfix = inToPost(infix);
    std::cout << postfix << std::endl;
    return 0;
}