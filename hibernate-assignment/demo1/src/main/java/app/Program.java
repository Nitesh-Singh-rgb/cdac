package app;


import java.util.logging.Level;
import java.util.logging.Logger;

import app.data.*;
import jakarta.persistence.Persistence;

public class Program {
    
    public static void main(String[] args) throws Exception {

        Logger.getLogger("org.hibernate").setLevel(Level.SEVERE);

        var em = Persistence.createEntityManagerFactory("app.data")
                        .createEntityManager();
       
      if(args.length==0){
        var query =  em.createQuery("SELECT e FROM Employee e ", Employee.class);
            query.getResultList()
            .stream()
            .forEach(e -> System.out.printf(
                "%d\t %s\t %s\t  %tF\t %.2f\t  %d%n",
                e.getEmpno(),
                e.getEname(),
                e.getJob(),
                e.getHireDate(),
                e.getSalary(),
               
                e.getDeptno()

            ));
      }
       
      em.close();
      
    }
}

