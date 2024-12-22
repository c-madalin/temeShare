package org.example;

public interface Product {

    public default String getName(){
    return "";}
    public default void setName(String name){}
    public default int getPrice(){
return 0;
    }
    public default void setPrice(int pret){}

}
