#ifndef CDB_H
#define CDB_H

class CDB
{
public:
    CDB(int bw = 1) : bandWidth(bw), rest(bw)
    { }

    bool avaliable() const
    {
        return rest > 0;
    }

    void setBusy()
    {
        rest = 0;
    }

    void setFree()
    {
        rest = bandWidth;
    }

    bool getCDB() 
    {
        if (avaliable()) {
            rest --;
            return true;
        }
        return false;
    }

//    void sendData(int r, double result);

private:
    int bandWidth;
    int rest;
};

#endif // CDB_H
