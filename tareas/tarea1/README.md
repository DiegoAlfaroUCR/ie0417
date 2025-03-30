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

### Scrum

Historia y origen de enfoque aquí.

* **Principios fundamentales**

* **Estructura del trabajo**

* **Ventajas**

* **Limitaciones**

* **Casos de uso adecuados**

### Kanban


Historia y origen de enfoque aquí.

* **Principios fundamentales**

* **Estructura del trabajo**

* **Ventajas**

* **Limitaciones**

* **Casos de uso adecuados**

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
