class Robot {
public:
    int w,h,p,tot;
    bool mv;

    Robot(int W,int H){
        w=W;h=H;p=0;
        tot=2*(w-1)+2*(h-1);
        mv=0;
    }

    void step(int x){
        mv=1;
        p=(p+x)%tot;
    }

    vector<int>getPos(){
        if(p<=w-1) return {p,0};
        if(p<=w-1+h-1) return {w-1,p-(w-1)};
        if(p<=2*(w-1)+h-1) return {w-1-(p-(w-1)-(h-1)),h-1};

        return {0,h-1-(p-2*(w-1)-(h-1))};
    }

    string getDir(){
        if(!mv) return "East";
        if(p>=1 && p<=w-1) return "East";
        if(p>w-1 && p<=w-1+h-1) return "North";
        if(p>w-1+h-1 && p<=2*(w-1)+h-1) return "West";

        return "South";
    }
};