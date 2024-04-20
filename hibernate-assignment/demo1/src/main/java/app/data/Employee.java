package app.data;

import java.sql.Date;

import jakarta.persistence.Column;
import jakarta.persistence.Entity;
import jakarta.persistence.Id;
// import jakarta.persistence.NamedQuery;
import jakarta.persistence.Table;
@Entity
@Table(name="emp")

public class Employee{
    
    @Id
    @Column(name="empno")
    private int empno;

    @Column(name="ename")
    private String ename;

    @Column(name="job")
    private String job;

    // @Column(name="mgr")
    // private int manager;

    @Column(name="hiredate")
    private Date hireDate;

    @Column(name="sal")
    private double salary;

    // @Column(name="comm")
    // private double commision;

    @Column(name="deptno")
    private int deptno;

    public int getEmpno() {
        return empno;
    }

    public void setEmpno(int empno) {
        this.empno = empno;
    }

    public String getEname() {
        return ename;
    }

    public void setEname(String ename) {
        this.ename = ename;
    }

    public String getJob() {
        return job;
    }

    public void setJob(String job) {
        this.job = job;
    }

    // public int getManager() {
    //     return manager;
    // }

    // public void setManager(int manager) {
    //     this.manager = manager;
    // }

    public Date getHireDate() {
        return hireDate;
    }

    public void setHireDate(Date hireDate) {
        this.hireDate = hireDate;
    }

    public double getSalary() {
        return salary;
    }

    public void setSalary(double salary) {
        this.salary = salary;
    }

    // public double getCommision() {
    //     return commision;
    // }

    // public void setCommision(double commision) {
    //     this.commision = commision;
    // }

    public int getDeptno() {
        return deptno;
    }

    public void setDeptno(int deptno) {
        this.deptno = deptno;
    }

     
}