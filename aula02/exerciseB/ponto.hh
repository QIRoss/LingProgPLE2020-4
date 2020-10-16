using namespace std;

class Ponto {
    public:
        Ponto (double = 1.0, double = 1.0, double = 1.0);

        double getCoordX ();
        double getCoordY ();
        double getCoordZ ();
        
        void setCoordX (double);
        void setCoordY (double);
        void setCoordZ (double);
    private:
      double coordX, coordY, coordZ;
};