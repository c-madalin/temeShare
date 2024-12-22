package pachet;

public class Masina {
    private String m_model;
    private int m_year;

    public Masina() {}

    public Masina(String model, int year) {
        m_model = model;
        m_year = year;
    }
    public int getYear()
    {
        return m_year;
    }
    public String getModel()
    {
        return m_model;
    }
    public void setYear(int year)
    {
        m_year = year;
    }
    public void setModel(String model)
    {
        m_model = model;
    }

    public void Accelereaza()
    {
        System.out.println("Accelereaza");
    }
    public void afiseazaDatele()
    {
        System.out.println("Masina este un "+ m_model + " din anul " + m_year);
    }
}
