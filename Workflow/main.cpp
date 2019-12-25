#include <stdexcept>
#include "Workflow.h"


int main(int argc, char ** argv) {
    if (argc != 2){
        throw std::invalid_argument("Wrong arguments amount!");
    }
    Workflow wf(argv[1]);
    wf.execute();
    return 0;
}