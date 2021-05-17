#include<bits/stdc++.h>
using namespace std;

int main() {
    long long int wWidth , wHeight , tWidth , tHeight , cTile , cCut , tiles , cost , width , height;
    cin >> wWidth >> wHeight >> tWidth >> tHeight >> cTile >> cCut;
    
    (wWidth%tWidth) ? width = (wWidth/tWidth)+1 : width = (wWidth/tWidth) ;
    (wHeight%tHeight) ? height = (wHeight/tHeight)+1 : height = (wHeight/tHeight) ;
    
    tiles = height*width;

    (tiles%10) ? tiles = (tiles/10)+1 : tiles = (tiles/10) ;
    cost = tiles*cTile;
    
    tWidth *= width;
    tHeight *= height;
    
    if((tWidth!=wWidth) && (tHeight!=wHeight))
        cost += ((wWidth+wHeight)*cCut);
    else if(tWidth!=wWidth)
        cost += (wHeight*cCut);
    else if(tHeight!=wHeight)
        cost += (wWidth*cCut);
        
    cout << cost << "\n";
}