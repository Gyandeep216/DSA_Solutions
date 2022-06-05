//https://www.codingninjas.com/codestudio/problems/sort-a-stack_985275?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

void stackInsert(int val, stack<int> &stack){
    if(stack.empty() || stack.top()<val){
        stack.push(val);
        return;
    }
    
    int curr = stack.top();
    stack.pop();
    
    stackInsert(val,stack);
    
    stack.push(curr);
}


void sortStack(stack<int> &stack)
{
    if(stack.empty()){
        return;
    }
    
    int val = stack.top();
    stack.pop();
    
    sortStack(stack);
    
    stackInsert(val,stack);
}
