int main(){
int ch,dots,bytes,temp;

dots = bytes = temp = 0;
printf("enter ip adress (x.x.x.x) : ");
while((ch = getchar()) != '\n' && ch != EOF){
    if(ch < '0' || ch > '9'){
        if(ch == '.')
        {
            dots++;
            if(temp != -1)
            {
                if(temp > 255)
                {
                    printf("the value of each byte should be in [0,255]\n");
                }
                bytes++;
                temp = -1;
            }
        }else{
            printf("error acceptable chars are only digits and dots\n");
        }
    }else
    {
        if(temp == -1)
        {
            temp = 0;
        }
        temp = 10*temp + (ch-'0');
    }
}
if(temp != -1)
{
    if(temp > 255)
    {
        printf("the value of each byte should be in [0,255]\n");
        return 0;
    }
    bytes++;
}
if(dots != 3 || bytes != 4)
{
    printf("error : the ip format should be x.x.x.x\n");
}else
{
    printf("the input adress is a valid Ipv4 adress\n");
}
