int main() {
    float a;
    a = 1.0e1;
    int b = 0;
    //int c = a + b; //error!
    float d = a + b;
    d = a * b;
    if(!b){}
    if(!a){}
    else if(a>1){}
    else if(a<(float)1.2){}
    else if(a>=b){}
    else if(a<=b){}
    else if(a==(float)2.1){}
    else if(a&&b){}
    else{}
    return 0;
}
