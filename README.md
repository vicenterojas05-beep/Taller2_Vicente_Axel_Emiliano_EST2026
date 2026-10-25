# Sistema de gestión para hospital – Taller N°2 EST

## Integrantes

- **Axel Alcayaga (AxelAlcayaga)** - Ingeniería Civil en Computación e Informática - 20.832.945-6
- **Vicente Rojas (vicenterojas05-beep)** - Ingeniería Civil en Computación e Informática - 22.141.463-2
- **Emiliano Toro (EmiToro)** - Ingeniería en Tecnologías de Información - 21.512.702-8

## Instrucciones para ejecutar

Instrucciones para compilar en GitHub Codespaces:

Hacer click derecho sobre la carpeta en donde esta el programa y seleccionar abrir en terminal integrado
Ejecutar el siguiente comando para compilar:
g++ *.cpp -o hospital -std=c++11

Ejecutar el programa con:
./hospital


## Justificación del Criterio de Decisión

El árbol de clasificación jerarquiza las derivaciones médicas priorizando factores etarios y de riesgo vital:

Filtro Etario (Pediatría): Todo paciente con edad menor a 15 años es derivado de forma inmediata a esta unidad.

Intervenciones Críticas (Cirugía y Traumatología): En adultos, se prioriza el requerimiento quirúrgico (RequiereCirugia == 1) y la presencia de daño físico severo (Trauma == 1).

Especialidades de Riesgo (Neurología y Cardiología): Se aíslan de forma temprana los casos con síntomas neurológicos positivos y dolores focales en el pecho.

Evaluación de Urgencia: Si el paciente no pertenece a una especialidad específica, se miden los signos vitales críticos. Una temperatura >= 39.0°C o un dolor >= 8 deriva el caso a Urgencias.

Derivación General (Hospitalización y Medicina General): Los pacientes estables son asignados a Hospitalización si los días estimados son >= 1, o a Medicina General como servicio por defecto para la atención de menor riesgo.

