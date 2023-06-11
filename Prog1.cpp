#include <iostream>
#include <string>

struct node {
  int data;
  struct node *a;
  struct node *b;
  struct node *s; //closure state
};

int main() {
  // initialize the DFSM
  struct node *A = new node();
  struct node *BCEFHI = new node();
  struct node *DIJKLN = new node(); //final state
  struct node *GFHI = new node();
  struct node *JKLN = new node(); //final state
  struct node *MLN = new node();  //final state
  struct node *S = new node(); //state closure

  A->a = BCEFHI;
  A->b = nullptr; //nullptr = deadstate
  BCEFHI->a = DIJKLN;
  BCEFHI->b = GFHI;
  DIJKLN->a = JKLN;
  DIJKLN->b = MLN;
  DIJKLN->s = S; //S = closure state after input of $
  GFHI->a = JKLN;
  GFHI->b = GFHI;
  JKLN->a = nullptr;
  JKLN->b = MLN;
  JKLN->s = S;
  MLN->a = nullptr;
  MLN->b = MLN;
  MLN->s = S;

  std::cout << "Please enter a string for L=a(a|b*)ab* over the alphabet {a,b} ending with $: ";
  std::string input {};
  std::cin >> input;

  struct node *current = A; //current start from head

  for (auto it = input.begin(); it != input.end(); ++it) {
    
    if (*it == 'a' && current->a != nullptr) {
      current = current->a;
    }
    else if (*it == 'b' && current->b != nullptr) {
      current = current->b;
    }
    else if (*it == '$' && current->s != nullptr) {
      current = current->s;
      break;
    }
    else {
      current = nullptr; //nullptr = deadstate, exit and return "NO"
      break;
    }
  }

  std::string output = "NO";
  if (current == S) {
    output = "YES";
  }
  std::cout << output << std::endl;

  std::cout << "Thank you for using this program. Goodbye\n";
  return 0;
}