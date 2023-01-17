#define INPUT 0

class RockPiPin
{
public:
    RockPiPin();
    RockPiPin(int r, int p);
    ~RockPiPin();
    void zetInMode(int);
    void waardePin(int);
    int leesPinWaarde() const;
    int gpioPin()const;
    void gpioNr(int);
    
private:

   int richting=INPUT;
   int pinNr;
   int status;

};