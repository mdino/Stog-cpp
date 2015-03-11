struct t_putnik
{
        int oib,god;
        char prezime[40],ime[40], spol[1], b[20];
};
struct t_svi_putnici {
        t_putnik elem;
        t_svi_putnici *najgornji;
};

t_putnik vrh_stoga (t_svi_putnici *stog)
{
        return stog->najgornji->elem;
}
void Init (t_svi_putnici *stog)
{
        stog->najgornji=NULL;
}
bool IsEmpty (t_svi_putnici *stog)
{
        if (stog->najgornji==NULL) {
                return true;
        }
        return false;
}
void ubaci_na_vrh (t_putnik novi_putnik, t_svi_putnici *stog)
{
        t_svi_putnici *novi=new t_svi_putnici;
        novi->elem=novi_putnik;
        novi->najgornji=stog->najgornji;
        stog->najgornji=novi;
}
void izbaci_sa_vrha (t_svi_putnici *stog)
{
        t_svi_putnici *prvi=stog->najgornji;
        stog->najgornji=prvi->najgornji;
        delete prvi;
}
