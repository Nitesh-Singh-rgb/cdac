package hosting;

import java.lang.reflect.InvocationHandler;
import java.lang.reflect.Method;
import java.lang.reflect.Proxy;

public class ServiceContainer {
    
    @SuppressWarnings("unchecked")
    public static <I, J extends I> I getService(Class<I> iface, Class<J> impl) throws Exception {
        System.out.printf("Configuring environment for %s service.%n", impl.getSimpleName());
        if(impl.isAnnotationPresent(OnePerCall.class)){
            var proxyHandler = new InvocationHandler() {
                public Object invoke(Object proxyObject, Method targetMethod, Object[] args) throws Exception {
                    Object targetObject = impl.getConstructor().newInstance();
                    return targetMethod.invoke(targetObject, args);
                }
            };
            return  (I)Proxy.newProxyInstance(impl.getClassLoader(), impl.getInterfaces(), proxyHandler);
        }
        return impl.getConstructor().newInstance();
    }

}
