#include "Stack.h"

int main()
{
    Stack<int> stack;
    std::cout << stack.empty() << std::endl;
    stack.push(1);
    stack.push(2);
    stack.push(5);
    std::cout << stack.top() << "  " << stack.size() << "  " << stack.empty() << std::endl;
    stack.pop();
    stack.pop();
    stack.pop();
    std::cout << stack.empty() << std::endl;
    return 0;
}
