struct t_putnik
{
        int oib,god;
        char prezime[40],ime[40],spol[1], b[20];
};
struct t_svi_putnici {
        t_putnik elem[1001];
        int najgornji;
};
t_svi_putnici *stog;
void izbaci_sa_vrha (t_svi_putnici *stog)
{
        stog->najgornji++;
}
void Init(t_svi_putnici *stog)
{
        stog->najgornji=1000;
}
bool IsEmpty(t_svi_putnici *stog)
{
        if (stog->najgornji==1000) return true;
        return false;
}
t_putnik vrh_stoga (t_svi_putnici *stog)
{
        return stog->elem[stog->najgornji + 1];
}

void ubaci_na_vrh (t_putnik novi_putnik, t_svi_putnici *stog)
{
        stog->elem[stog->najgornji]=novi_putnik;
        stog->najgornji--;
}




