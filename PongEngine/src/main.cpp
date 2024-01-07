#include <cstdlib>

#include "PongEngine.h"


int main()
{
    const auto engine = GE::create_engine();
    engine->init();
    engine->run();
    engine->exit();
    return EXIT_SUCCESS;
}
