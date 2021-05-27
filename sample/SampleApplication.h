#include <Dog/Application.h>

class SampleApplication : public Dog::Application
{
public: 
    SampleApplication() = default;

    void Update() override;
};