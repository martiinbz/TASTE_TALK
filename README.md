****ESTRUCTURA DE DATOS Y ALGORITMOS II, 2022-2023****                                                                       Adrià Casals/Martín Bárcena/Arnau Gil
            RED  SOCIAL: Taste Talk
            
***INTRODUCCIÓN***

Para este trabajo debíamos de crear una red social desde cero, de temática libre pero con algunos objetivos obligatorios. En lo demás, se nos dejaba bastante 
libertad sobre cómo abordar el trabajo, aunque disponíamos de una guía que marcaba más o menos lo que se debía realizar cada sesión de prácticas, esta era 
meramente simbólica, pues cada grupo podía decidir el orden y la manera de hacer las cosas.

Hemos escogido crear una red social tematizada en el ámbito de la cocina,ya que nos pareció algo innovador, diferente y muy poco visto.
El nombre de esta red social es “Taste Talk”. Para el nombre, intentamos inventarnos uno nosotros, aunque sin éxito. Preguntamos entonces a ChatGPT por ideas,
y esta es la que más original nos pareció.
Taste Talk es un lugar donde los usuarios pueden compartir sus recetas, sus gustos culinarios y sus comidas del día a día.

Para cumplir los objetivos propuestos, hemos tenido que ayudarnos también de material de internet, ya que solamente con el conocimiento adquirido en clase era 
prácticamente imposible. Este material utilizado nos ha sido de gran ayuda, pues nos ha dado información, inspiración y conocimientos muy útiles sobre cómo 
afrontar y resolver los diversos problemas con los que nos hemos encontrado a la hora de desarrollar la red social.

**OBJETIVOS DEL PROYECTO**

*Objetivos obligatorios alcanzados:*

· Implementar como mínimo una Lista (List), una Pila (Stack) y una Cola (Queue) funcionales como parte de alguna de las funcionalidades del proyecto.

    -La lista la hemos usado para almacenar los nombres de usuario de todos los usuarios registrados en la aplicación. Hemos creado una lista dinámica que 
    almacena todos los usernames. Además, lo hemos hecho para que el índice de esta lista corresponda con el índice del array de estructuras, así, al pasar una
    función de búsqueda sobre esta lista, devolverá no solo la posición de la lista en la que se encuentra el usuario buscado, sino también la posición en la que 
    se encuentra en la estructura, facilitando así muchísimo el acceder a la información de cada usuario.

    La cola la hemos implementado a la hora de gestionar las solicitudes de amistad. La estructura de la cola es un poco rara, pero funciona igual que una. Hemos 
    creado una estructura enlazada al typedef de usuarios que contiene la ID del usuario que manda la solicitud y la ID del que la recibe.
    Entonces, se añade el ID al apartado de la estructura del receptor destinado a almacenar las solicitudes pendientes(es un array).
    Por último, para gestionar estas solicitudes, se van vaciando las posiciones de la cola, y se hace lo correspondiente dependiendo de si el usuario decide 
    aceptar o no la solicitud. Intentamos usar la cola de la manera convencional, pero debido a los problemas que nos daba, decidimos modificarla de esta manera,
    esto nos retrasó bastante, ya que le dedicamos bastante tiempo para que luego no nos funcionase y la tuviésemos que modificar.

    Por último la pila, que aunque en un principio creamos la estructura y funciones de una pila dinámica (pensamos en usarla para almacenar los usuarios, pero
    finalmente pensamos que una lista sería mejor idea) no la hemos acabado implementando. Queríamos también implementarla para almacenar las publicaciones, pero 
    nos dio bastantes problemas y optamos por hacerlo con un método más sencillo.

    -Tiempo: 
        *Lista dinámica: 60min
        *Cola:120mins
        *Pila: 60mins

    -Ubicación: 
        *Lista: declaración en menu_principal.c, lineas 43-44, pero se le reasigna memoria en varias partes del código. 
        *Cola: estructura en estructuras.h, lineas 31-34. Se usa en las funciones relacionadas con las solicitudes, ubicadas en enviar_solicitudes.c. 
        *Pila: la estructura se encuentra en estructuras.h, lineas 25-30. Las funciones se encuentran en funciones_pila_usuario.c (la pila no se usa).

· Implementar funcionalmente uno de los algoritmos de búsqueda que se verán dentro del curso (LinearSearch o BinarySearch).

    -En nuestra red social, hemos implementado un algoritmo de búsqueda secuencial que se ha utilizado en múltiples ocasiones a lo largo del código. Esta 
    función desempeña un papel crucial, ya que permite encontrar la posición de un usuario específico en la lista de usuarios mediante un bucle for, devolviendo 
    su índice correspondiente. Este índice es de suma importancia, porque proporciona acceso a la estructura de datos asociada a ese usuario en especifico. 
    La función de búsqueda secuencial se utiliza en diversas ocasiones durante la ejecución del programa. Por ejemplo, se emplea para verificar si un usuario 
    específico está registrado en la red social. Además, esta función se utiliza para obtener el ID del usuario correspondiente, lo que nos permite llevar a cabo 
    una serie de acciones importantes, como validar su contraseña o realizar operaciones en nombre de ese usuario específico. Gracias a esta función de búsqueda 
    secuencial,podemos localizar rápidamente la posición de un usuario en la lista de usuarios y acceder a su información ubicada en la estructura de datos. 
    En resumen, el algoritmo de búsqueda secuencial que hemos implementado en nuestra red social es una herramienta esencial que nos permite localizar y acceder 
    a la información de los usuarios de manera eficiente y segura. Su utilización en varias partes del código nos ayuda a realizar distintas tareas, como la 
    verificación de usuarios, la validación de contraseñas y poder realizar acciones como un usuario en específico.

    -Tiempo: 5min
    -Ubicación: declaración en login.c, líneas 5-12. Uso durante varias partes del código.

· Implementar funcionalmente uno de los algoritmos de ordenamiento que se verán a lo largo del curso (InsertionSort, BubbleSort, MergeSort o QuickSort).

    -Uno de los objetivos para este proyecto era implementar uno de losalgoritmos de sorting vistos en clase. Nosotros hemos decidido implementar el algoritmo de BubbleSort, un algoritmo simple, pero efectivo, ya que tampoco íbamos a necesitar recorrer un array excesivamente grande.

    Este algoritmo lo hemos usado para ordenar las palabras contenidas en el diccionario de las publicaciones según su número de apariciones, para así luego poder saber las tendencias de la aplicación (las 10 palabras más usadas).
    Estos algoritmos son de suma importancia para hacer nuestra red social más eficiente y conseguir tiempos de ejecución menores.
    Tiempo: 30 min.
    Ubicación: diccionario.c, lineas 47-58

· Implementar o bien un Diccionario (Dictionary) o bien una tabla Hash (HashTable) funcionales.

    -Algo a tener en cuenta a la hora de gestionar una red social es saber cuales son las tendencias, es decir, de lo que más se habla. Es por eso que hemos introducido una función que lee las publicaciones de los usuarios y almacena las palabras en un diccionario, si esta palabra ya se encuentra en el diccionario, entonces aumenta en 1 su número de apariciones.
    Después, usando un algoritmo de ordenamiento, seremos capaces de ordenar las palabras del diccionario según el número de apariciones y así poder saber las palabras más utilizadas en nuestra red social.
    La implementación de este diccionario viene en varias partes, pues se necesita una estructura de datos que contenga cada palabra y el número de apariciones, además también tiene que estar conectada al struct de usuario, ya que cada usuario tiene publicaciones diferentes. Luego también se necesita otra función con 3 bucles: uno para iterar por la estructura de usuarios, otro para iterar por las publicaciones de un usuario específico y uno último para separar una publicación en palabras e irlas añadiendo al diccionario.
    Tiempo: 120min
    Ubicación: estructura en estructuras.h, lineas 61-65. función para añadir al diccionario en diccionario.c, lineas 17-45


· Todas las partes importantes de tu código deben estar comentadas:

    Esta parte es fundamental para que el código sea entendible y legible para todos los miembros del equipo y el profesor. Todo el código debe de estar comentado, 
    para que así todos los que lo lean puedan entenderlo y saber para qué sirve y qué hace cada cosa. Hemos intentado comentar todo lo que hemos podido y de la 
    mejor manera posible, indicando brevemente la función de las líneas más importantes del código. Ir comentando todo a medida que íbamos programando nos ha 
    ayudado a tener el código mejor organizado y   nos ha servido para que no se nos olvide para qué sirven las cosas si estás unos cuantos días sin trabajar en 
    el proyecto (esto pasa mucho), también ha ayudado a comunicarnos entre nosotros, ya que si tu haces una función y explicas lo que hace y la comentas, luego 
    cuando tu compañero se meta a trabajar podrá entender lo que has hecho y seguir trabajando desde ahí.

    Tiempo: durante todo el proyecto
    Ubicación: todo el código.

· Usar github para que todos los miembros del equipo puedan trabajar a la par y más cómodamente. Los diferentes miembros del equipo deben mostrar actualizaciones 
del código constantes. 

    Durante el transcurso de la realización de la práctica, hemos ido implementando el uso del GitHub, que es una herramienta muy útil para 
    poder permitir que el proyecto que se está realizando esté al alcance de todos los miembros del grupo, permitiendo que estos puedan ir actualizando a medida 
    que un compañero consiga un fragmento de código pedido en alguna sesión de prácticas de esta asignatura. Al principio del proyecto no hubieron los conocidos 
    “commit and push” y uso del GitHub debido a que nos causó ciertos problemas, como por ejemplo, en la manera de descargarlo o de subirlo, ya que no se nos 
    actualizaba el fragmento de código como era debido. Preferimos optar por el uso del Code with me, ya que de esta manera no aparecían problemas y se podía ir 
    actualizando simultáneamente mientras cada miembro del grupo se ocupaba de una parte. Al acabar las sesiones, el miembro que estaba compartiendo su proyecto, 
    lo guardaba, y en caso de que un compañero quisiera editar o implementar algún fragmento de código se le enviaba el código. Más tarde, pudimos solucionar el 
    problema que nos ocurría con la actualización del código gracias al conocimiento del profesor, ya que este nos brindó ayuda después de que le preguntamos y le 
    adjuntamos los errores en formato de imagen. Una vez conseguimos eso, si alguien hacía algo en casa, se subía al GitHub, para que así se pueda descargar o 
    actualizar más fácil y el otro miembro pueda editarlo en su tiempo libre. En conclusión, hemos adquirido el objetivo de haber  implementado el uso del GitHub 
    para poder facilitar la constante actualización del código a medida que pasaba el tiempo y las sesiones.
    
    Tiempo: durante todo el proyecto

*Objetivos deseables alcanzados*

· Leer y registrar en la red social los usuarios de un fichero .txt

    -Uno de los logros destacables que hemos alcanzado en nuestro proyecto es la implementación de la capacidad de leer datos de una fuente externa. En nuestro 
    caso, hemos trabajado en la creación de un archivo de texto (txt) en el cual hemos almacenado los datos de 20 usuarios. Estos datos incluyen información como 
    nombres, contraseñas, gustos y más. Esta fue una tarea crucial para asegurar la eficiencia y comodidad del proceso de registro en nuestra red social.
    La opción 2 de nuestro menú ofrece una funcionalidad muy interesante: la posibilidad de registrar instantáneamente a los usuarios previamente almacenados en
    el archivo txt. Esto significa que con tan solo seleccionar esta opción, los usuarios pueden completar su registro de manera rápida y sencilla, sin tener que 
    ingresar manualmente cada detalle de su información.
    La generación de la lista de usuarios y sus respectivas informaciones fue posible gracias a la ayuda de la inteligencia artificial de OpenAI CHAT-GPT 3. 
    Esta avanzada tecnología nos permitió obtener 20 usuarios aleatorios con todos los datos necesarios para el registro. La capacidad de la inteligencia artificial
    para generar información coherente y realista ha sido fundamental en este proceso, ya que nos ha permitido agilizar y simplificar la creación de cuentas en 
    nuestra red social temática.

    Tiempo: aproximadamente 60 minutos.
    Ubicación: usuarios.txt y menu_prinicipal.c (lineas 104-109 del código)

· Red social temática

    -La creación de una red social temática ha sido uno de nuestros principales objetivos, ya que buscábamos ofrecer a los usuarios una experiencia única y especializada. Después de evaluar diversas ideas innovadoras, 
    llegamos a la conclusión de que una red social de comida sería una opción fascinante y sin precedentes. Ninguno de los tres miembros del grupo había escuchado hablar antes de una propuesta similar, lo que nos motivó
    aún más a desarrollar esta idea.
    Nuestra red social de comida está diseñada específicamente para que los usuarios puedan compartir sus recetas favoritas, así como los platos deliciosos que han disfrutado durante el día. Esto resuelve uno de los
    problemas comunes en muchos hogares: la falta de inspiración a la hora de decidir qué cocinar para las comidas o cenas. Con tan solo unos cuantos clics, nuestros usuarios tendrán acceso a un amplio abanico de ideas culinarias, lo que les permitirá disfrutar de deliciosas comidas sin tener que lidiar con la incertidumbre de qué preparar.
    Además de compartir recetas, nuestra red social también ofrece una comunidad activa y amigable de amantes de la comida. Los usuarios podrán intercambiar consejos y trucos culinarios, e incluso participar en desafíos y concursos gastronómicos mediante las publicaciones. Esta interacción social en torno a la comida crea un ambiente acogedor donde los usuarios pueden conectarse, compartir experiencias y ampliar sus horizontes culinarios.
    En resumen, nuestra red social temática de comida no solo resuelve el dilema diario de qué cocinar, sino que también fomenta una comunidad de apasionados por la gastronomía. Es un lugar donde la creatividad, la inspiración y el intercambio de ideas culinarias florecen. Conviértete en parte de nuestra red y descubre un mundo de sabores y emocionantes descubrimientos culinarios. ¡La aventura gastronómica te espera!
    Tiempo empleado: aproximadamente 20 minutos.
    Ubicación: todo el código


**SOLUCIÓN**
*Arquitectura del sistema* 

            En nuestro sistema hemos empleado los siguientes bloques: 
            Aplicación: En esta parte, se encuentran las instrucciones y características esenciales de la aplicación. Es el lugar donde se procesan los datos y se maneja la comunicación entre la base de datos y la   º               interfaz de usuario.
            Servidor: En nuestro caso no se considera un bloque principal pero si fuese una red social online lo tendríamos que haber implementado para que diferentes usuarios desde diferentes dispositivos pudiesen interactuar a la vez.
            Base de datos: Nuestra base de datos se basa en un fichero llamado usuarios.txt. En él nos encontramos una lista de 20 usuarios con su respectivos datos (nombres, contraseñas, etc), de esta manera, estos usuarios pueden ser registrados automáticamente al pulsar una de las opciones del menú.
            Interfaz de usuario: Esta parte de la aplicación es donde nos comunicamos con la red social. Aquí es donde solicitamos información como nombres, preferencias y otros datos a través de la pantalla. También es donde se nos muestra la variedad de menús e interfaces. La interfaz es la encargada de solicitar los datos que luego se guardarán en las bases de datos y estructuras.

*Gestión de errores:*

    Durante el proyecto nos hemos encontrado con un gran número de errores y problemas que al principio no sabíamos solventar. Algunos de estos fallos los hemos
    podido solucionar gracias a Internet y sus herramientas, por otra parte, han sido los profesores los encargados de ayudarnos con los errores que ni siquiera
    Internet nos podía ayudar a solucionar. 
    Nuestras trabas más significativas nos las encontramos en:

· Leer el fichero txt:  

    Durante esta parte del trabajo nos encontramos con que no sabíamos cómo modificar nuestro código para que se leyesen los datos que habían dentro del fichero. 
    El punto está en que el programa abría el fichero pero no leía los datos que habíamos insertado. Esto, tras rompernos la cabeza, lo consultamos con nuestro 
    profesor de prácticas, Héctor Florido Fontanet, el cual nos brindó la solución a nuestro problema.

· Uso del GitHub: 

    Al inicio del trabajo tuvimos varios problemas con esta plataforma ya que al subir el código habían partes que no se actualizaban. Es por eso que, tal
    y como hemos comentado al principio de este reporte, optamos por la opción de usar CodeWithMe. Fue en una clase en la que le preguntamos al profesor como 
    arreglar nuestra falla. Este nos ayudó y pudimos empezar a usar el GitHub.

· Envío de solicitudes:

    La tarea de enviar solicitudes desde la sesión iniciada de un usuario a otro usuario fue otra de las tareas que más nos costó. Al principio no sabíamos 
    cómo enfocar el código para que hiciese esta función, después, cuando logramos entender cómo hacerlo, vimos que no solo enviaba la solicitud al usuario deseado,
    sino que enviaba la solicitud a todos los usuarios registrados. Para solucionar esto estuvimos revisando y modificando el código una y otra vez hasta que 
    finalmente dimos con la línea de código que fallaba y, como suele pasar en el código de un programa, el error resultó ser una tontería minúscula que nos 
    desmontaba toda la función.
    





