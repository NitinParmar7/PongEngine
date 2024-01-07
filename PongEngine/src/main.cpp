
#include <cstdlib>

#include "PongEngine.h"


int main()
{
    const auto engine = GE::create_engine();
    engine->init(engine->GetWidth(), engine->GetHeight(), engine->GetTitle());
    return EXIT_SUCCESS;
}
