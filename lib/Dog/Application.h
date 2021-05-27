#include <Dog/Macros.h>

BEGIN_DOG_NAMESPACE()

class Application
{
public:
    void Run();

    virtual void Update() = 0;
};

END_DOG_NAMESPACE()