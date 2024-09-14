//percentage.h
float att_percent(int aper, float high_amark, float diff) 
{   
    float marks = 0;
   
    for (int i = 95,j = 0 ; i >= 50; i -= 5, j++) 
    
    {
        if (aper >= i) 
        {
            marks = high_amark - (diff * j);
            break;
        }
    }

    return marks;
}