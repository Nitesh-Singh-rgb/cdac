package app.data;

import java.util.List;



import jakarta.persistence.Column;
import jakarta.persistence.Entity;
import jakarta.persistence.Id;
import jakarta.persistence.JoinColumn;
import jakarta.persistence.OneToMany;
import jakarta.persistence.Table;

@Entity
@Table(name = "dept")
public class Department{

    @Id
    @Column(name="deptno")
    private int deptno;

    @Column(name="dname")
    private String deptName;

    @Column(name="loc")
    private String location;

    @OneToMany
    @JoinColumn(name="deptno")
    private List<Employee>employees;
    
    public List<Employee> getEmployess() {
        return employees;
    }

    public void setEmployess(List<Employee> employees) {
        this.employees = employees;
    }

    public int getDeptno() {
        return deptno;
    }

    public void setDeptno(int deptno) {
        this.deptno = deptno;
    }

    public String getDeptName() {
        return deptName;
    }

    public void setDeptName(String deptName) {
        this.deptName = deptName;
    }

    public String getLocation() {
        return location;
    }

    public void setLocation(String location) {
        this.location = location;
    }

  
}