package com.company;

import java.util.Scanner;

public class Icecream {
    private static int id_gener = 1;
    private int id;
    private String name;
    private String country;
    private int massa;
    private int milk;
    private int expiration_date;
    private int chocolate;
    private Data date_post;
    public Icecream()
    {
        name = "IceBerg";
        massa = 400;
        milk = 300;
        expiration_date = 120;
        chocolate = 0;
        country = "Germany";
        this.date_post = new Data();
    }
    public Icecream(String nazv)
    {
        name = nazv;
        massa = 400;
        milk = 300;
        expiration_date = 120;
        chocolate = 0;
        country = "Germany";
        this.date_post = new Data();
    }
    public Icecream(String nazv, int mas, int sod_milk, int ex_date, int ch, String countr, int x, int y, int k)
    {
        name = nazv;
        massa = mas;
        milk = sod_milk;
        expiration_date = ex_date;
        chocolate = ch;
        this.date_post = new Data(x, y, k);
        country = countr;
    }
    public String Read_String() {
        Scanner str=new Scanner(System.in);
        String st=str.nextLine();
        str.close();
        return st;
    }
    public int Read_Int(){
        Scanner in =new Scanner(System.in);
        int k = in.nextInt();
        in.close();
        return k;
    }
    public void Display(){
        String out="Name:"+name;
        System.out.println(out);
        out="massa:"+massa;
        System.out.println(out);
        out="milk:"+milk;
        System.out.println(out);
        out="expiration date:"+expiration_date;
        System.out.println(out);
        out="chocolate:"+chocolate;
        System.out.println(out);
        date_post.Display();
        out="Country:"+country;
        System.out.println(out);
    }
    public int Add(Icecream ice1,Icecream ice2){
        Icecream ice3=new Icecream();
        ice3.massa=ice1.massa+ice2.massa;
        return ice3.massa;
    }
    public void Country(){
        System.out.println(country);
    }
    public void output_date_postavk(){
        date_post.output_date_postavk();
    }
    public int one (Icecream icecream){
        return icecream.massa+100;
    }
    public int two(){
        return one(this);
    }
    public int get_massa(){
        return massa;
    }

    //создание уникального ID с помощью статической переменной id_gener
    public int get_id(){
        id=id_gener++;
        return id;
    }
    //статический метод для получения значения текущего ID без создания объекта класса
    public static int get_id_now(){
        return id_gener;
    }

}
