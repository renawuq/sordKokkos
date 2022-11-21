#ifndef PARAMETER_CPP
#define PARAMETER_CPP
#include "parameters.h"

parameters::parameters(){
    nodelist[1]     = "x1";
    nodelist[2]     = "x2";
    nodelist[3]     = "x3";
    nodelist[4]     = "f1";
    nodelist[5]     = "f2";
    nodelist[6]     = "f3";
    nodelist[7]     = "a1";
    nodelist[8]     = "a2";
    nodelist[9]     = "a3";
    nodelist[10]    = "am2";
    nodelist[11]     = "v1";
    nodelist[12]     = "v2";
    nodelist[13]     = "v3";
    nodelist[14]    = "vm2";
    nodelist[15]     = "u1";
    nodelist[16]     = "u2";
    nodelist[17]     = "u3";
    nodelist[18]    = "um2";
    nodelist[19]    = "co";
    nodelist[20]    = "mus";
    nodelist[21]    = "mud";
    nodelist[22]    = "dc";
    nodelist[23]    = "af";
    nodelist[24]    = "bf";
    nodelist[25]    = "v0";
    nodelist[26]    = "f0";
    nodelist[27]   = "ll";
    nodelist[28]    = "fw";
    nodelist[29]    = "vw";
    nodelist[30]    = "psi";
    nodelist[31]    = "ath";
    nodelist[32]    = "ahy";
    nodelist[33]    = "rhoc";
    nodelist[34]    = "tplam";
    nodelist[35]    = "tpw";
    nodelist[36]    = "tini";
    nodelist[37]    = "pini";
    nodelist[38]    = "tempw";
    nodelist[39]    = "tau_c";
    nodelist[40]    = "aspD";
    nodelist[41]    = "lpc";
    nodelist[42]    = "ts";
    nodelist[43]    = "td";
    nodelist[44]    = "tn";
    nodelist[45]    = "area";
    nodelist[46]    = "nhat1";
    nodelist[47]    = "nhat2";
    nodelist[48]    = "nhat3";
    nodelist[49]    = "temp";
    nodelist[50]    = "porep";
    nodelist[51]    = "vwv";
    nodelist[52]    = "t1";
    nodelist[53]    = "t2";
    nodelist[54]    = "t3";
    nodelist[55]    = "ts1";
    nodelist[56]    = "ts2";
    nodelist[57]    = "ts3";
    nodelist[58]    = "tsm";
    nodelist[59]    = "tnm";
    nodelist[60]    = "tneff";
    nodelist[61]    = "fr";
    nodelist[62]    = "sa1";
    nodelist[63]    = "sa2";
    nodelist[64]    = "sa3";
    nodelist[65]    = "sam";
    nodelist[66]    = "sv1";
    nodelist[67]    = "sv2";
    nodelist[68]    = "sv3";
    nodelist[69]    = "svm";
    nodelist[70]    = "psv";
    nodelist[71]    = "su1";
    nodelist[72]    = "su2";
    nodelist[73]    = "su3";
    nodelist[74]    = "sum";
    nodelist[75]    = "sl";
    nodelist[76]    = "erf";
    nodelist[77]    = "ere";
    nodelist[78]    = "eft";
    nodelist[79]    = "trup";
    nodelist[80]    = "tarr";

    celllist[1]     = "c1";
    celllist[2]     = "c2";
    celllist[3]     = "c3";
    celllist[4]     = "vc";
    celllist[5]     = "a11";
    celllist[6]     = "a22";
    celllist[7]     = "a33";
    celllist[8]     = "a23";
    celllist[9]     = "a31";
    celllist[10]    = "a12";
    celllist[11]     = "rho";
    celllist[12]     = "vp";
    celllist[13]     = "vs";
    celllist[14]    = "gam";
    celllist[15]     = "mco";
    celllist[16]     = "phi";
    celllist[17]     = "plb";
    celllist[18]    = "plh";
    celllist[19]    = "mu";
    celllist[20]    = "lam";
    celllist[21]    = "yy";
    celllist[22]    = "bk";
    celllist[23]    = "plcls";
    celllist[24]    = "epm";
    celllist[25]    = "gammap";
    celllist[26]    = "s11";
    celllist[27]   = "s22";
    celllist[28]    = "s33";
    celllist[29]    = "s23";
    celllist[30]    = "s31";
    celllist[31]    = "s12";
    celllist[32]    = "e11";
    celllist[33]    = "e22";
    celllist[34]    = "e33";
    celllist[35]    = "e23";
    celllist[36]    = "e31";
    celllist[37]    = "e12";
    celllist[38]    = "w11";
    celllist[39]    = "w22";
    celllist[40]    = "w33";
    celllist[41]    = "w23";
    celllist[42]    = "w31";
    celllist[43]    = "w12";
    celllist[44]    = "wm2";
    celllist[45]    = "mr11";
    celllist[46]    = "mr22";
    celllist[47]    = "mr33";
    celllist[48]    = "mr23";
    celllist[49]    = "mr31";
    celllist[50]    = "mr12";
}
// skip the case i1pml, i2pml, period = '10*dt'
void parameters::readPara(std::string filename)
{
    infile.open(filename);
    std::string line; 
    while (std::getline(infile, line))
    {
        firstWord.clear();
        line.erase(std::remove(line.begin(), line.end(), ','), line.end());
        line.erase(std::remove(line.begin(), line.end(), '('), line.end());
        line.erase(std::remove(line.begin(), line.end(), ')'), line.end());

        pos = line.find_first_of(" ");
        firstWord.push_back(line.substr(0, pos));
        temp = firstWord.at(0); 
        track = 0; 
        pos = line.find(" ", pos+1);
        line = line.substr(pos+1);
        tmp = "";
        //std::cout << temp << line <<"???" << "\n";
        if(temp == "")
            continue;
        else if(temp == "nn"){
            assignOneArray(line, nn, 3);
        }
        else if(temp == "nt"){
            assignOneValue(line, nt);
        }
        else if(temp == "dx"){
            assignOneArray(line, dx, 3);
        }
        else if(temp == "tm0"){
            assignOneValue(line, tm0);
        }
        else if(temp == "dt"){
            assignOneValue(line, dt);
        }
        else if(temp == "affine"){
            std::cout << "affine: " << line << "\n";
            assignDoubleArray(line, affine);
        }
        else if(temp == "n1expand"){
            assignOneArray(line, n1expand, 3);
        }
        else if(temp == "n2expand"){
            assignOneArray(line, n2expand, 3);
        }
        else if(temp == "gridnoise"){
            assignOneValue(line, gridnoise);
        }
        else if(temp == "oplevel"){
            assignOneValue(line, oplevel); 
        }
        else if(temp =="rho1"){
            assignOneValue(line, rho1); 
        }
        else if(temp =="rho2"){
            assignOneValue(line, rho2); 
        }
        else if(temp == "vp1"){
            assignOneValue(line, vp1); 
        }
        else if(temp == "vp2"){
            assignOneValue(line, vp2); 
        }
        else if(temp == "vs1"){
            assignOneValue(line, vs1); 
        }
        else if(temp == "vs2"){
            assignOneValue(line, vs2); 
        }
        else if(temp == "gam1"){
            assignOneValue(line, gam1); 
        }
        else if(temp == "gam2"){
            assignOneValue(line, gam2); 
        }
        else if(temp == "vdamp"){
            assignOneValue(line, vdamp); 
        }
        else if(temp == "hourglass"){
            assignOneArray(line, hourglass, 2);
        }
        else if(temp == "bc1"){
            assignOneArray(line, bc1, 3);
        }
        else if(temp == "bc2"){
            assignOneArray(line, bc2, 3);
        }
        else if(temp == "ppml"){
            assignOneValue(line, ppml);
        }
        else if(temp == "npml"){
            assignOneValue(line, npml);
        }
        else if(temp == "vpml"){
            assignOneValue(line, vpml);
        }
        else if(temp == "ihypo"){
            std::cout << "ihypo " << line << "\n";
            assignOneArray(line, ihypo, 3);
        }
        else if(temp == "source"){
            assignStringValue(line, source);
        }
        else if(temp == "timefunction"){
            assignStringValue(line, timefunction);
        }
        else if(temp == "strike"){
            assignOneValue(line, strike);
        }
        // float not work for this case 
        else if(temp == "dip"){
            assignOneValue(line, dip);
        }
        else if(temp == "rake"){
            assignOneValue(line, rake);
        }
        else if(temp == "m0"){
            assignOneValue(line, m0);
        }
        else if(temp == "source1"){
            assignOneArray(line, source1, 3);
        }
        else if(temp == "source2"){
            assignOneArray(line, source2, 3);
        }
        else if(temp == "nsource"){
            assignOneValue(line, nsource);
        }
        else if(temp == "ivols"){
            assignStringValue(line, ivols);
        }
        else if(temp == "eplasticity"){
            assignStringValue(line, eplasticity);
        }
        else if(temp == "plmodel"){
            assignStringValue(line, plmodel);
        }
        else if(temp == "pleta"){
            assignOneValue(line, pleta);
        }
        else if(temp == "tv"){
            assignOneValue(line, tv);
        }
        else if(temp == "tpnz"){
            assignOneValue(line, tpnz);
        }
        else if(temp == "tpsubdt"){
            assignOneValue(line, tpsubdt);
        }
        else if(temp == "tp_method"){
            assignStringValue(line, tp_method);
        }
        else if(temp == "tp_vw"){
            assignStringValue(line, tp_vw);
        }
        else if(temp == "friction"){
            assignStringValue(line, friction);
        }
        else if(temp == "pcdep"){
            assignStringValue(line, pcdep);
        }
        else if(temp == "faultnormal"){
            assignOneValue(line, faultnormal);
        }
        else if(temp == "slipvector"){
            assignOneArray(line, slipvector, 3);
        }
        else if(temp == "faultopening"){
            assignOneValue(line, faultopening);
        }
        else if(temp == "vrup"){
            assignOneValue(line, vrup);
        }
        else if(temp == "rcrit"){
            assignOneValue(line, rcrit);
        }
        else if(temp == "trelax"){
            assignOneValue(line, trelax);
        }
        else if(temp == "rrelax"){
            assignOneValue(line, rrelax);
        }
        else if(temp == "tslope"){
            assignOneValue(line, tslope);
        }
        else if(temp == "rnucl"){
            assignOneValue(line, rnucl);
        }
        else if(temp == "tmnucl"){
            assignOneValue(line, tmnucl);
        }
        else if(temp == "delts"){
            assignOneValue(line, delts);
        }
        else if(temp == "svtol"){
            assignOneValue(line, svtol);
        }
        else if(temp == "np3"){
            assignOneArray(line, np3, 3);
        }
        else if(temp == "itstats"){
            assignOneValue(line, itstats);
        }
        else if(temp == "itio"){
            assignOneValue(line, itio);
        }
        else if(temp == "itcheck"){
            assignOneValue(line, itcheck);
        }
        else if(temp == "itstop"){
            assignOneValue(line, itstop);
        }
        else if(temp == "debug"){
            assignOneValue(line, debug);
        }
        else if(temp == "mpin"){
            assignOneValue(line, mpin);
        }
        else if(temp == "mpout"){
            assignOneValue(line, mpout);
        }
        else if(temp == "fieldio"){
            // fieldlist.insertNode();
            // gio->mode = xx
            // bool switch1 = true; 
            // while(switch1){
            //     for(char&c : line){ 
            //         if(c == ']')
            //         {
            //             switch1 = false;
            //             break;
            //         }
            //         if(c== '=' || c =='+')
            //         {

            //         }
            //     }
            //     getline(infile, line);
            std::cout << line;
            bool switch1 = true; 
            while(switch1){
                if(line[0] == ']')
                    {
                        std::cout << "end when " << line << "\n";
                        switch1 = false;
                        break;
                    }
                int index = 0;
                bool tool = false; 
                for(char& c : line) {
                    if(c == '='){
                        tool = true; 
                    }
                    else if(tool == true && c == 'w'){
                        mode = "=w";
                        readFieldio(line.substr(index+4));
                        tool=false;
                    }
                    else if(tool == true){
                        mode = "=";
                        readFieldio(line.substr(index+3));
                        tool = false;
                    }
                    index++;
                }
            //std::cout << "line : " << line << "\n";
            getline(infile,line);
        }
                
            
            
            
        }
}   
}
void parameters::readFieldio(std::string line)
{
    std::cout<<"just checking: " << line << "\n";
    int tempInt = 0; 
    tmp ="";
    for (int i = 2 ; i < 13; i++){
        if(i == 2){
            for(char&c : line){
                if(isdigit(c)){
                    tmp +=c; 
                }
                else{
                    nc = std::stoi(tmp);
                    break;
                }
            }
            tempInt++;
        }
        tempInt+=1;
        tmp = "";
        if(i==3){
            line = line.substr(tempInt+std::to_string(nc).length()-1);
            //std::cout << "linenc: " << line << "\n";
            assignStringValue(line, tfunc);
        }
        if(i == 4){
            line = line.substr(tfunc.length()+4);
            assignOneValue(line, period);
            std::cout << period << "\n";
        }
        tmp = "";
        bool keepAdd = true; 
        int tempInt1 = 0;
        int tempInt2 = 0;
        int tempInt3 = 0;
        if(i==5){
            for(char&c : line){
                if(c == '('){
                    keepAdd = false; 
                }
                else if(c ==')'){
                    std::string lineTmp = line.substr(tempInt1+1, tempInt2-1);
                    lineTmp.erase(std::remove(lineTmp.begin(), lineTmp.end(), ','), lineTmp.end());
                    line = line.substr(tempInt3);
                    //std::cout << "line1: " << line << "\n";
                    assignOneArray(lineTmp, x1,3);
                    break;
                }
                if(keepAdd)
                    tempInt1++; 
                else
                    tempInt2++;
                tempInt3++;
            }
        }

        tmp = "";
        keepAdd = true; 
        tempInt1 = 0;
        tempInt2 = 0;
        tempInt3 = 0; 
        if(i==6){
            // std::cout << "line1: " << line << "\n";
            line = line.substr(1);

            for(char&c : line){
                if(c == '('){
                    keepAdd = false; 
                }
                else if(c ==')'){
                    std::string lineTmp = line.substr(tempInt1+1, tempInt2-1);
                    lineTmp.erase(std::remove(lineTmp.begin(), lineTmp.end(), ','), lineTmp.end());
                    //std::cout << "line2: " << lineTmp << "\n";
                    line = line.substr(tempInt3);
                    assignOneArray(lineTmp, x2, 3);
                    break;
                }
                if(keepAdd)
                    tempInt1++; 
                else
                    tempInt2++;
                tempInt3++;
            }
        }
        if(i==7){
            line = line.substr(3);
            assignOneValue(line, nb);
            std::cout << "nb: " << nb << "\n";
        }
        tempInt3 = 0;
        tmp = "";
        if(i == 8){
            line = line.substr(std::to_string(nb).length()+2);
            std::cout << "i =8: " << line << "\n";
            for(char&c : line){
                if(c == ']'){
                    tmp.erase(std::remove(tmp.begin(), tmp.end(), '['), tmp.end());
                    tmp.erase(std::remove(tmp.begin(), tmp.end(), '('), tmp.end());
                    tmp.erase(std::remove(tmp.begin(), tmp.end(), ')'), tmp.end());
                    tmp.erase(std::remove(tmp.begin(), tmp.end(), ','), tmp.end());
                    line = line.substr(tempInt3);
                    std::cout << "tmp: " << tmp << "\n";
                    assignDoubleArray2(tmp, ii);
                    break;
                }
                tmp+=c; 
                tempInt3++;
            }
        }

        if(i == 9){
            line = line.substr(3);
            // std::cout << "i = 9: " << line << "\n";
            if(line[1]=='-'){
                filename = "-";
            }
            else{
                assignStringValue(line, filename);
            }
            std::cout << "filename is " << filename << "\n";
        }

        if(i == 10){
            line = line.substr(filename.length()+4);
            // std::cout << "i = 10: " << line << "\n";
            assignOneValue(line, val);
            std::cout << "val is " << val << "\n";
        }
        tmp = "";
        if (i == 11){
            bool addTem = false; 
            for(char &c : line){
                if(c=='[')
                    addTem = true;
                else if(c==']')
                {
                    field = tmp;
                    break;
                }
                else if(addTem && (isalpha(c) || isnumber(c)))
                    tmp+=c; 
            }
        }
        std::cout << "field is: " << field << "\n";
    }
    std::cout << "mode is: " << mode << " nc is: " << nc << " tfunc is: " << tfunc << " period is: " << period << "\n";
    //fiel.insertNode(mode,nc,tfunc,period,x1,x2,nb,ii,filename,val, field);
}

void parameters::assignOneValue(std::string line, int &num)
{
    int tool1 = 0;
    for(char& c : line) {
        if(!isdigit(c)&&c!='-' && c!='e'){
            if(tmp[0]=='-')
                num = 0 - std::stoi(tmp.substr(1, tmp.length()));
            else
                num =std::stoi(tmp); 
            break;
        }
        else
            tmp+=c;                    
    }
    if (tool1 == 0)
    {
        if(tmp[0]=='-')
                num = 0 -std::stof(tmp.substr(1, tmp.length()));
            else
                num =std::stof(tmp); 
    }
}
void parameters::assignOneValue(std::string line, float &num)
{
    int tool1 = 0; 
    for(char& c : line) {
        if(!isdigit(c)  && c!='.' && c!='-' && c!='e'){
            tool1++; 
            //std::cout << "line1: " << line << " current: " << tmp << "\n";
            if(tmp[0]=='-')
                num = 0 -std::stof(tmp.substr(1, tmp.length()));
            else
                num =std::stof(tmp); 

            break;
        }
        else
            tmp+=c;          
            //std::cout << "line2: " << line << " current: " << tmp << "\n";
    }
    if (tool1 == 0)
    {
        if(tmp[0]=='-')
                num = 0 -std::stof(tmp.substr(1, tmp.length()));
            else
                num =std::stof(tmp); 
    }
}
void parameters::assignOneArray(std::string line, int num[], int size){
    for(char& c : line) {
        if(track <size && (!isdigit(c)&& c!='.')){
            num[track]=std::stoi(tmp); 
            track++; 
            tmp = ""; 
        }
        else if(track>=size){
            break;   
        }
        else
            tmp+=c;                    
    }
    if(track<size){
        num[track]=std::stof(tmp); 
    }
}
void parameters::assignOneArray(std::string line, float num[], int size){
    for(char& c : line) {
        if(track <size && (!isdigit(c)&& c!='.')){
            //std::cout << " tmp is : " << tmp << " " << "track: " << track << "\n";
            num[track]=std::stof(tmp); 
            track++; 
            tmp = ""; 
        }
        else if(track>=size){
            //std::cout <<"track: " << track << "\n";
            break;   
        }
        else
            tmp+=c; 
            //std::cout << " tmp22 is : " << tmp << "\n";                   
    }
    if(track<size){
        num[track]=std::stof(tmp); 
    }

}

void parameters::assignDoubleArray(std::string line, float num[3][3]){
    int doubleIndex = 0; 
    for(char& c : line) {
        if(c == '#')
            break; 
        if(doubleIndex <3 && (!isdigit(c)&& c!='.')&& tmp.size() > 0){
            if(track>=3)
            {
                doubleIndex++;
                track= 0;
                num[doubleIndex][track]=std::stof(tmp); 
            }
            else
            {
                num[doubleIndex][track]=std::stof(tmp); 
            }
            track++; 
            tmp = "";
        }
        else if(isdigit(c) || c == '.')
            tmp+=c;                    
    }
}
void parameters::assignDoubleArray2(std::string line, float num[4][3]){
    //std::cout << "er: " << line << "\n";
    int doubleIndex = 0; 
    tmp = "";
    track = 0;
    for(char& c : line) {
        if(!isspace(c)){
            tmp += c; 
        }
        else{
            if(track < 3){
                num[doubleIndex][track] = stof(tmp);
                //std::cout << "tmp1: " << tmp << "\n";
                track++;
                tmp ="";
            }
            else{

                doubleIndex+=1;
                track = 0 ;
                num[doubleIndex][track] = stof(tmp);
                track++;
                //std::cout << "tmp2: " << tmp << "\n";
                tmp="";
            }
        }
    }
    //std::cout << "tmp: " << tmp << "\n";

    num[3][2] = std::stof(tmp);
    for(int i =0; i < 4; i++)
    {
        for(int j =0; j <3; j++)
        {
            std::cout << num[i][j] << " ";
        }
        std::cout << "\n";
    }
}

void parameters::assignStringValue(std::string line, std::string &tool)
{
    int num = 0; 
    for(char& c : line) {
        if(num ==0)
            num++;
        else if(isalpha(c)){
            tmp+=c;
            num++;
        }
        else{
            tool = tmp;
            break;
        }
    }
}

void parameters::printAll(){
    std::cout << " nn[0]: " << nn[0] << "\n" << " nn[1]: " << nn[1]<< "\n" << " nn[2]: " << nn[2]<< "\n" << " nt: " << nt 
    << "\n"<< " dx[0]: " << dx[0] << "\n"<< " dx[1]: " << dx[1] << "\n"<<" dx[2]: " << dx[2] << "\n"<< " tm0: " 
    << tm0 << "\n"<< " dt: "  << dt << "\n"<< " n1expand[0]: " << n1expand[0] << "\n"<< " n1expand[1]: "
     << n1expand[1] << "\n"<< " n1expand[2]: "<< n1expand[2] << "\n"<< " n2expand[0]: "  << n2expand[0] << "\n"
    << " n2expand[1]: "  << n2expand[1]<< "\n" << " n2expand[2]: " << n2expand[2]<< "\n" <<  " gridnoise[0]: "
     << gridnoise <<"\n" << " oplevel: " << oplevel <<"\n"<< " rho1: " << rho1 <<"\n" << " rho2: " << rho2 <<"\n"
     << " vp1: " << vp1 <<"\n"  << " vp2: " << vp2 <<"\n"<< " vs1: " << vs1 <<"\n"  << " vs2: " << vs2 <<"\n"
     << " gam1: " << gam1 <<"\n"  << " gam2: " << gam2 <<"\n"<< " vdamp: " << vdamp <<"\n"  << " hourglass[0]: " 
     << hourglass[0] <<"\n" << " hourglass[1]: " << hourglass[1] <<"\n" << " ppml: " << ppml << "\n" 
     << " vpml: " << vpml  << "\n" << " npml: " << npml <<"\n" << " source: " << source << "\n"
     << " timefunction: " << timefunction <<"\n" << " strike: " << strike << "\n"<< " dip: " << dip << "\n"
     << " rake: " << rake << "\n" << " m0: " << m0 << "\n"<< " nsource: " << nsource << "\n"
     << " ivols: " << ivols << "\n" << " eplasticity: " << eplasticity << "\n" << " plmodel: " << plmodel << "\n"
     << " pleta: " << pleta << "\n" << " tv: " << tv << "\n"<< " tpnz: " << tpnz << "\n"
     << " tpsubdt: " << tpsubdt << "\n" << " tp_method: " << tp_method << "\n" << " tp_vw: " << tp_vw << "\n"
     << " friction: " << friction << "\n" << " pcdep: " << pcdep << "\n"<< " faultnormal: " << faultnormal << "\n"
     << " faultopening: " << faultopening << "\n" << " vrup: " << vrup << "\n"
     << " rcrit: " << rcrit << "\n" << " trelax: " << trelax << "\n" << " tslope: " << tslope << "\n" << " rnucl: " << rnucl << "\n"
     << " tmnucl: " << tmnucl << "\n" << " delts: " << delts << "\n" << " svtol: " << svtol << "\n"
     << " itstats: " << itstats << "\n" << " itio: " << itio << "\n" << " itcheck: " << itcheck << "\n"
     << " itstop: " << itstop << "\n" << " debug: " << debug << "\n" << " mpin: " << mpin << "\n"
     << " mpout: " << mpout << "\n";
    
    std::cout<<"\n";
    std::cout<< "affine: " << "\n";
    for(int i =0; i < 3; i++)
    {
        for(int j =0; j <3; j++)
        {
            std::cout << affine[i][j] << " ";
        }
        std::cout << "\n";
    }
    for(int i =0; i < 3; i++)
    {
        std::cout << "bc1: [" << i << "]: " << bc1[i] << "\n";
        std::cout << "bc2: [" << i << "]: " << bc2[i] << "\n";
        std::cout << "ihypo: [" << i << "]: " << ihypo[i] << "\n";
        std::cout << "source1 [" << i << "]: " << source1[i] << "\n";
        std::cout << "source2 [" << i << "]: " << source2[i] << "\n";
        std::cout << "slipvector [" << i << "]: " << slipvector[i] << "\n";
        std::cout << "np3 [" << i << "]: " << np3[i] << "\n";

    }
}

#endif