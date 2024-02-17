#include <bits/stdc++.h>
using namespace std;
 vector <double> projection(int x ,int y,int r)
{
    vector <double> ans={0,0};
     if(x==300)
     {
         ans[0]=300;
         if(y>=300)
             ans[1]=300+r;
         else
             ans[1]=300-r;
         //cout<<ans[0]<<" "<<ans[1]<<endl;
         return ans;
     }
     double a=(300.0-y)/(300.0-x);
     double aa=a*a+1,bb=-600*(a*a+1),cc=90000+((300*a)*(300*a))-(r*r);
     double res1=((-bb)+sqrt((bb*bb)-(4*aa*cc)))/(2*aa);
     double res2=((-bb)-sqrt((bb*bb)-(4*aa*cc)))/(2*aa);
     if(abs(x-res1)<abs(x-res2))
     {
         ans[0] = res1;
         ans[1]=(a*res1)+300-(300*a);
     }
     else
     {
         ans[0] = res2;
         ans[1]=(a*res2)+300-(300*a);
     }
     //cout<<ans[0]<<" "<<ans[1]<<endl;
     return ans;
}

int main() {
    int n;
    cout<<"請輸入有幾個點?";
    cin>>n;
    cout<<"請依序輸入每個點的座標"<<endl;
    int* x;
    x=new int[n];
    int* y;
    y=new int[n];
    vector <vector<double>> ans,ans2,ans2_1;
    for(int i=0;i<n;i++)
    {
        cin>>x[i]>>y[i];
    }
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        vector <double> out =projection(x[i],y[i],300);
        vector <double> in =projection(x[i],y[i],150);
        ans.push_back(out);
        if(pow(x[i]-out[0],2)+pow(y[i]-out[1],2)<=pow(x[i]-in[0],2)+pow(y[i]-in[1],2))
            ans2.push_back(out);
        else
            ans2_1.push_back(in);
    }
    vector <vector<double>> tmp=ans;
    sort(tmp.begin(),tmp.end());
    for(int i=0;i<n;i++)
        if(tmp[i][1]>=300)
            cout<<"("<<tmp[i][0]<<","<<tmp[i][1]<<")";
    sort(tmp.begin(),tmp.end(),greater<vector<double>>());
    for(int i=0;i<n;i++)
        if(tmp[i][1]<300)
            cout<<"("<<tmp[i][0]<<","<<tmp[i][1]<<")";
    cout<<endl;
    tmp.clear();
    tmp=ans2;
    cout<<"Outer:";
    sort(tmp.begin(),tmp.end());
    for(int i=0;i<tmp.size();i++)
        if(tmp[i][1]>=300)
            cout<<"("<<tmp[i][0]<<","<<tmp[i][1]<<")";
    sort(tmp.begin(),tmp.end(),greater<vector<double>>());
    for(int i=0;i<tmp.size();i++)
        if(tmp[i][1]<300)
            cout<<"("<<tmp[i][0]<<","<<tmp[i][1]<<")";
    cout<<endl;
    tmp.clear();
    tmp=ans2_1;
    cout<<"inter:";
    sort(tmp.begin(),tmp.end());
    for(int i=0;i<tmp.size();i++)
        if(tmp[i][1]>=300)
            cout<<"("<<tmp[i][0]<<","<<tmp[i][1]<<")";
    sort(tmp.begin(),tmp.end(),greater<vector<double>>());
    for(int i=0;i<tmp.size();i++)
        if(tmp[i][1]<300)
            cout<<"("<<tmp[i][0]<<","<<tmp[i][1]<<")";
    cout<<endl;
    system("pause");
}
