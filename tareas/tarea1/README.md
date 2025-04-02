# Modelos ágiles y herramientas de gestión de proyectos en la industria del software

## 1. Herramientas de gestión de proyectos de software (tecnología de apoyo)

### [Jira](https://www.atlassian.com/software/jira/agile)

Software desarrollado por la compañía [Atlassian](https://www.atlassian.com/) que permite el seguimiento del desarrollo, problemas, bugs, cambios y demás de un proyecto de software. Siendo una aplicación para [ALM](https://aws.amazon.com/es/what-is/application-lifecycle-management/) (Application Lifecycle Management, o administración del ciclo de vida de las aplicaciones), Jira se especializa en productos para desarrolladores y directores de proyectos (project managers) como formas de administrar proyectos en todos los aspectos correspondientes a su ciclo de vida.

* **Principales Funcionalidades:** Jira se distribuye en [paquetes distintos](https://www.techtarget.com/searchsoftwarequality/definition/Jira): **Jira Core**, **Jira Software**, **Jira Service Management** y **Jira Align**, cada uno posee ciertas diferencias según el enfoque de uso que se requiere en el proyecto. Jira Core se centra en la administración de negocios, algunas de sus funciones son la planeación/seguimiento de tareas por medio de [workflows](https://www.techtarget.com/searchcio/definition/workflow) y generación de reportes. Jira Software es el paquete enfocado en seguimiento de tareas/problemas en software, incluye funciones usadas por desarrolladores de software/equipos de DevOps como paneles para reportes en Scrum y Kanban. Jira service management, utilizado por equipos de soporte técnico para manejar problemas, dar seguimiento a metas definidas en el SLA (Service Level Agreement), etc. Finalmente, Jira Align el cual se enfoca en desarrollo de software con metodologías ágiles, permite alinear el equipo de desarrollo por medio de roadmaps en objetivos comunes.

* **Relación con metodologías:** Jira presenta soporte amplio al uso de metodologías ágiles en el proceso de desarrollo. En conjunto con [Jira Align](https://www.atlassian.com/software/jira-align), la herramienta permite hacer registros digitales de los user stories, priorizarlas y generar las tareas a cumplir. Para coordinar correctamente a los equipos en la herramienta se pueden asignar las tareas a los desarrolladores según corresponda, y asignarla a la etapa apropiada del proceso según indica la metodología usada (por ejemplo asignar una tarea a un sprint en procesos de Scrum).

### [Azure DevOps](https://azure.microsoft.com/en-us/products/devops)

Software desarrollado por Microsoft que proporciona un conjunto de herramientas para la planificación, desarrollo, pruebas e implementación de software. Siendo una plataforma para ALM, integra diversas funcionalidades para la administración del ciclo de vida del desarrollo, facilitando la colaboración entre equipos y la entrega continua de software. Está disponible en dos formas: "Server" cuando se ejecuta de forma local y "Services" cuando se emplean los servicios en línea. Se pueden utilizar los servicios de Azure DevOps de forma integrada en clientes IDE (Integrated Development Enviroments) como Visual Studio.

* **Principales Funcionalidades:** Se tienen varios [servicios de Azure DevOps](https://learn.microsoft.com/en-us/azure/devops/user-guide/what-is-azure-devops?view=azure-devops) con funciones distintas. **Azure Boards** presentan herramientas para uso en metodologías ágiles que permiten dar seguimiento al trabajo realizado/problemas encontrados, con métodos de Scrum y Kanban. **Azure Repos** proporciona control de versiones mediante Git y TFVC (Team Foundation Version Control). **Azure Pipelines** ofrece integración y entrega continua (CI/CD), compatible con múltiples lenguajes y entornos. **Azure Test Plans** facilita la gestión de pruebas automatizadas y manuales para garantizar la calidad del software. **Azure Artifacts** proporciona almacenamiento y gestión de paquetes para facilitar la distribución de dependencias.

* **Relación con metodologías:** [Azure DevOps está diseñado para integrarse con metodologías ágiles y DevOps](https://learn.microsoft.com/en-us/azure/devops/boards/work-items/guidance/agile-process-workflow?view=azure-devops), permitiendo una gestión eficiente de proyectos de desarrollo. Se pueden organizar tareas en sprints (Scrum) o flujos de trabajo (Kanban). Con Azure Pipelines, se automatizan las pruebas y despliegues, alineándose con las prácticas de integración y entrega continua. Se pueden definir user stories, sus puntajes de dificultad y organizarlas según su prioridad. 

### [ClickUp](https://clickup.com/)

Plataforma de administración de proyectos y productividad diseñada para adaptarse a diversos tipos de equipos y metodologías de trabajo. Se da en forma de una plataforma unificada en línea, la cual incluye las funcionalidades de varias herramientas para que el flujo de trabajo se de en una herramienta centralizada.

* **Principales Funcionalidades:** ClickUp incluye una gran cantidad de funciones que se dividen en [categorías](https://clickup.com/) según el tipo de tareas que cumplen. **Manejo de proyectos**, se organizan las tareas en portafolios y se usan diagramas de Gantt para identificar los tiempos de desarrollo permitidos. **Desarrollo de productos**, se tienen funcionalidades para elaborar Sprints/reportes de Sprints para metodologías Scrum y tableros para Kanban. **Colaboración/Manejo de conocimiento**, se usa una herramienta para la elaboración de documentación integrada, pizarras, chats y búsquedas. **Manejo de recursos**, se tienen funciones para medir el tiempo de desarrollo, los objetivos logrados, y demás métricas.

* **Relación con metodologías:** ClickUp es altamente adaptable a metodologías ágiles como Scrum y Kanban, permitiendo la creación de sprints, gestión de backlog y asignación de tareas en tableros visuales. Incluso se menciona en la página principal la posibilidad de usar metodologías como Waterfall con las herramientes disponibles en ClickUp.

### Comparación

Las 3 herramientas descritas poseen gran utilidad en el desarrollo de proyectos de software con metodologías ágiles. Jira y Azure DevOps parecen ser de las herramientas más populares y usadas en este ámbito, con Jira mencionando varias compañías que la usan en sus procesos de desarrollo. Sin embargo, Azure DevOps posee una mejor integración con otras plataformas, principalmente IDEs como Visual Studio y Oracle. En términos de facilidad de uso, dependiendo de la cultura de trabajo del equipo alguna de las herramientas será más fácil de utilizar. Sin embargo, se considera que la simplicidad y amplitud de funciones integradas de ClickUp hace que sea más fácil de adoptar para un equipo no experimentado. Si el equipo de desarrollo requiere de funcionalidades más específicas de procesos agile es más recomendable usar Jira o Azure DevOps (especialmente si se desarrolla en ambientes de Microsoft o servicios de Azure).

## 2. Marco teórico profundo de Scrum y Kanban

### [Scrum](https://www.scrum.org/)

La metodología que posteriormente sería conocida como Scrum [fue inicialmente planteada](https://www.thescrummaster.co.uk/wp-content/uploads/2016/09/SCRUM-Development-Process-K-Schwaber.pdf) en 1986 por Hirotaka Takeuchi y Ikujiro Nonaka en [*The New New Product Development Game*](https://www.thescrummaster.co.uk/wp-content/uploads/2016/09/The-New-New-Product-Development-Game.pdf), donde estudian casos de metodologías usadas en industrias automobilísticas, de fotocopiado, cámaras, etc para formular su propia metodología. Esta tiene el enfoque de de equipos autoregulados (regido por roles asignados), velocidad y flexibilidad en el diseño (debido a que el proceso de diseño es impredecible) y fases ejecutadas simultáneamente (permitiendo que descubrimientos en fases posteriores influencen el desarrollo de las anteriores). [Ken Schwaber y Jeff Sutherland desarrollarían](https://www.agile42.com/en/blog/scrum-history) este enfoque en [el proceso de desarrollo SCRUM](https://www.thescrummaster.co.uk/scrum/short-history-scrum/) aplicándo los conceptos expuestos por Takeuchi y Nokana en el diseño de software. En años posteriores Schwaber, Sutherland, Kent Beck y otros aplicarían la metodología en sus equipos de trabajo e irían a fundar organizaciones como ScrumAlliance y acreditaciones como Professional Scrum o Certfied Scrum Master. En 2001 varios desarrolladores (incluidos Sutherland y Schwaber) crean el [manifesto de las metodologías ágiles](https://agilemanifesto.org/), entre los principios del mismo se incluyen aspectos del Scrum.

* **Principios fundamentales:** Diversas fuentes ([SCRUMstudy](https://www.scrumstudy.com/whyscrum/scrum-principles) y [Universidad de Arizona](https://www.uagc.edu/blog/what-is-scrum)) mencionan 6 principios fundamentales para el SCRUM: 

  * **Control de procesos empírico**: Debido a que en SCRUM las decisiones se realizan por medio de experimentación, es necesario que todas sean transparentes, inspeccionadas y adaptadas a lo requerido por el equipo y product owner.
  
  * **Auto-organización**: Se busca que los desarrolladores se organicen a sí mismos, puesto que si poseen motivación para sí mismos y un sentido de responsabilidad, se pueden organizar más efectivamente que por un manager. 
  
  * **Colaboración:** Se advoca que en el proceso de desarrollo los equipos de trabajo y los product owners/accionistas colaboren, permitiendo que los aportes de cada uno influencen en el trabajo del otro.
  
  * **Priorización basada en valor:** La metodología se enfoca en entregar productos que generen valor de forma temprana y contínua, para permitir la retroalimentación y dar la mayor cantidad de valor en el tiempo disponible.
  
  * **Time-Boxing:** Se proponen lapsos de tiempo máximos para cada tarea, evitando que se tome mucho tiempo en una sola.
  
  * **Desarrollo iterativo**: El proceso de desarrollo retoma sus etapas varias veces, asegurando que cambios en los requerimientos sean asesorados y corrigan el curso de desarrollo.

* **Estructura del trabajo:** El flujo de trabajo en la metodología SCRUM está definido principalmente en las **ceremonias** realizadas entre los miembros del equipo, quienes toman distintos papeles en las mismas según sus **roles** y documentan el trabajo en los distintos **artefactos** del SCRUM. Todos estos aspectos del SCRUM giran en torno del **Sprint**.

   * **Sprint:** [Etapa central del método SCRUM](https://www.atlassian.com/agile/scrum/sprints), es un lapso de tiempo definido (time-boxed) en el que se trabaja para completar tareas definidas durante las ceremonias. Suele tener una duración de 1 a 4 semanas y es un proceso repetido varias veces durante el ciclo de desarrollo del proyecto.

   * **Ceremonias:** Siguiendo los principios de colaboración continua y control de procesos empírico, el SCRUM define multiples reuniones (llamadas ceremonias) las cuales permiten discutir requisitos, tareas a realizar en los sprints, recibir retroalimentación del trabajo realizado y mantener control del proceso en general. Se realizan ceremonias de **planeación** (discutir las prioridades del siguiente sprint), **compromiso** (revisar user stories a desarrollar en el sprint), **daily-standup** (mostrar el trabajo/complicaciones diarias), demostración o demo (mostrar las implementacions post-sprint) y **restrospectivas** (discutir lo logrado/fallado en el sprint ya finalizado).

   * **Roles:** Siguiendo el enfoque de colaboración y autoorganización, SCRUM define [distintos roles dentro del equipo ](https://www.atlassian.com/agile/scrum/roles), cada uno con responsabilidades específicas para garantizar la entrega efectiva del producto. Estos roles se dividen en tres categorías principales y trabajan en conjunto durante los sprints y ceremonias. **Product Owner:** Responsable de maximizar el valor del producto. Gestiona y prioriza el backlog, asegurándose de que el equipo trabaje en lo más importante para los stakeholders. Participa activamente en la planeación del sprint y en la validación de entregables. **Scrum Master:** Facilita la metodología SCRUM, eliminando impedimentos y asegurándose de que el equipo siga las prácticas adecuadas. Actúa como mentor para el equipo, ayuda a coordinar ceremonias y fomenta la mejora continua. **Development Team:** Grupo autoorganizado de profesionales que diseñan, desarrollan, prueban e implementan las funcionalidades del producto. Son responsables de comprometerse con los objetivos del sprint y entregar incrementos funcionales al final del mismo.

   * **Artefactos:** Para asegurar una gestión clara del trabajo y mantener la trazabilidad de los avances, SCRUM define una [serie de artefactos](https://www.atlassian.com/agile/scrum/artifacts) que documentan las tareas, prioridades y progreso del equipo durante los sprints. **Product Backlog:** Lista priorizada de requisitos, características y tareas del producto. Es administrado por el Product Owner y se actualiza continuamente a medida que se identifican nuevas necesidades o se refinan las existentes. **Sprint Backlog:** Subconjunto del Product Backlog que el equipo se compromete a completar en un sprint. Se define en la ceremonia de planeación y se actualiza durante el sprint para reflejar el progreso. **Incremento de Producto:** Resultado tangible al final de un sprint, que consiste en un conjunto de funcionalidades terminadas y listas para su entrega. Debe cumplir con la definición de "hecho" establecida por el equipo.

* **Ventajas:** Existen diversas ventajas de trabajar con la metodología SCRUM sobre un desarrollo desogranizado o incluso con Waterfall. La flexibilidad de la metodología permite responder ante cambios en los requisitos y problemas imprevistos. Las entregas continuas permiten entregar valor constante y la evaluación del proyecto antes de adquirir mucha deuda técnica o perder horas de trabajo en proyectos mal guiados. Todo esto permite mitigar errores de forma temprana y asegurar el producto más acertado a lo buscado posible.

* **Limitaciones:** La principal desventaja de la metodología SCRUM es la alta demanda de tiempo y dedicación que se requiere para cumplir con los requisitos. Las ceremonias involucran una o en varios casos más reuniones por día, y requieren la disponibilidad y colaboración de todos los miembros involucrados en el desarrollo (incluyendo product owners). Además, en casos donde los requisitos son muy simples o fijos, los beneficios de emplear SCRUM se disminuyen considerablemente. Además, se requiere mucha coordinación en los casos de SCRUM a escala.

* **Casos de uso adecuados:** Los [casos de uso más adecuados](https://codewave.com/insights/use-scrum-methodology-in-project-management/) para implementar bajo una metodología SCRUM son aquellos que requieren muchos cambios durante el proceso (como startups), casos provenientes de clientes sin conocimiento de requisitos o con requisitos de gran importancia (empresas sin contexto tecnológico o bancos/aseguradoras) y proyectos que requieran entregas rápidas y constantes (como servicios vigentes que requieran refactorización/migración).

### [Kanban](https://en.wikipedia.org/wiki/Kanban)


El método Kanban [tiene sus raíces](https://kanbantool.com/kanban-guide/kanban-history) en el sistema de producción de Toyota, desarrollado por Taiichi Ohno en la década de 1940 para mejorar la eficiencia en la fabricación de automóviles. Inspirado en la forma en que los supermercados gestionaban su inventario para reponer productos según la demanda, Toyota implementó un sistema de tarjetas visuales ("kanban" en japonés) para señalar cuándo era necesario reponer materiales en la línea de producción.

Con el tiempo, este enfoque se adaptó a la gestión de proyectos y desarrollo de software, principalmente debido al hecho que en la industria se estaban empezando a adoptar metodologías similares a las ágiles. Muchos aspectos de otras metodologías ágiles, como SCRUM, tuvieron influencia en lo que se convertiría el Kanban, por ejemplo [equipos que utilizaban SCRUM boards las emplearon en las Kanban boards](https://kanbantool.com/kanban-guide/kanban-history). En este periodo se adoptó la metodología en diversos equipos, uno de estos Microsoft en donde se aplicó una mezcla de SCRUM y Kanban denominada [Scrumban](https://kanbantool.com/kanban-guide/what-is-scrumban). 

* **Principios fundamentales:** El método Kanban se basa en [una serie de principios](https://www.atlassian.com/agile/kanban) que permiten mejorar el flujo de trabajo y la eficiencia en la entrega de valor:

  *  **Visualizar el trabajo:** Se utiliza un tablero Kanban donde las tareas se representan como tarjetas moviéndose a través de columnas que reflejan distintos estados del flujo de trabajo.

  * **Limitar el trabajo en progreso (WIP):** Para evitar sobrecarga y mejorar la entrega continua y designación de recursos, se establecen límites en la cantidad de tareas que pueden estar en desarrollo simultáneamente.

  * **Gestión del flujo:** Se monitorea el tiempo que tardan las tareas en moverse a través del sistema para identificar cuellos de botella y mejorar la eficiencia. Además, en el caso de dependencias entre etapas se evitan interrupciones.

  * **Implementar ciclos de retroalimentación:** Se incorporan revisiones periódicas para evaluar el rendimiento del sistema y realizar ajustes según sea necesario.

  * **Mejorar colaborativamente:**  Se fomenta una cultura de mejora continua basada en experimentación e innovación dentro del equipo.

* **Estructura del trabajo:** Kanban no impone roles específicos dentro del equipo, sino que se [centra en la gestión del flujo de trabajo ](https://www.atlassian.com/agile/project-management/kanban-principles). La estructura principal de Kanban se basa en:
  * **Tablero Kanban:** Herramienta visual donde las tareas se organizan en columnas que representan los distintos estados del flujo de trabajo, desde "Por hacer" hasta "Hecho".

  * **Tarjetas de trabajo:** Representan tareas o elementos de trabajo, conteniendo información relevante como responsables, prioridades y fechas límite.

  * **Columnas y estados:** Cada columna representa una etapa del proceso, como "Pendiente", "En progreso" y "Completado".

  * **Límites WIP:** Restricciones en la cantidad de tareas permitidas en cada columna para evitar la sobrecarga del equipo y optimizar el flujo.

  * **Métricas y monitoreo:** Se usan indicadores como el tiempo de ciclo y el tiempo de entrega para medir el rendimiento del sistema y realizar ajustes.

* **Ventajas:** Kanban ofrece diversas ventajas en la gestión del trabajo y el desarrollo de software: Se tiene flexibilidad en el orden de desarrollo de funciones, puesto que [no requiere planificación fija de iteraciones](https://www.atlassian.com/agile/kanban), permitiendo cambios de prioridad en cualquier momento.  Se reducen los ciclos de trabajo al enfocarse en el flujo continuo, se minimizan tiempos muertos y se mejora la eficiencia. Comparado con el SCRUM, no se requieren ceremonias formales, reduciendo el tiempo dedicado a reuniones. Se dan mejoras contínuas basadas en métricas y feedback constante para optimizar procesos.

* **Limitaciones:** A pesar de sus beneficios, Kanban también presenta ciertas limitaciones. No posee una estructura definida, pues no impone roles ni planificación fija, lo que puede generar confusión si no hay un equipo familiarizado con la metodología. Requiere compromiso constante para optimizar procesos y adaptarse a cambios. No define iteraciones fijas como Scrum, lo que puede dificultar la planificación, particularmente con clientes cuyos horarios no se acoplan fácilmente con los del equipo de desarrollo.

* **Casos de uso adecuados:** Kanban es ideal para proyectos con requisitos cambiantes y flujos de trabajo continuos, como en mantenimiento y soporte (Equipos de TI y DevOps que manejan tickets de incidentes y correcciones de errores) o  software que requiera entregas continuas. Un caso de uso ideal, pero que es difícil de categorizar, es los proyectos que involucren cambios de prioridades constantes, es decir que las funciones más urgentes cambien durante el proceso y se requiera refactorización del orden de desarrollo.

## 3. Casos reales de aplicación en la industria

### Caso 1.

* **Marco de trabajo usado**

* **Herramientas tecnológicas**

* **Metodologías en la cultura organizacional**

* **Beneficios/retos**

* **Reflexión**


### Caso 2.

* **Marco de trabajo usado**

* **Herramientas tecnológicas**

* **Metodologías en la cultura organizacional**

* **Beneficios/retos**

* **Reflexión**
