#ifndef MODEL_HPP
#define MODEL_HPP

class ModelListener;

class Model
{
public:
    Model();

    void bind(ModelListener* listener)
    {
        modelListener = listener;
    }

    void tick();
protected:
    ModelListener* modelListener;

public:
    void sendValueToTask2(int value);

private:
    int modelValue;
    int a;
};

#endif // MODEL_HPP
