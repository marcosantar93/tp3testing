# Testing de software embebido - Trabajo Practico 3
## Desarrollo de módulo de software utilizando TDD mediante el framework ceedling
El módulo de recepcion de mensajes de configuracion debe cumplir con los siguientes requerimientos.

1- Recibe un mensaje de configuracion como una cadena de caracteres

2- Comprueba el mensaje cumple con uno de los siguientes formatos:

	a. [codigo_de_configuracion]:[adc_a_configurar(0..3)],[tipo_de_sensor(presion=0,temperatura=1,corriente=2)],[intervalo_de_repote_en_segundos],[minimo_cambio_reportable]

	b. [codigo_de_inicio_de_reporte]:[adc_a_configurar(0..3)]

	c. [codigo_de_pausa_de_reporte]:[adc_a_configurar(0..3)]

3- Si el mensaje corresponde al formato "a.", configura el ADC y un timer con el reporte a enviar.

4- Si el mensaje corresponde al formato "b.", comprueba si el timer asociado al ADC se encontraba corriendo y en caso negativo, lo reanuda.

5- Si el mensaje corresponde al formato "c.", comprueba si el timer asociado al ADC se encontraba corriendo y en caso positivo, lo detiene.

6- El intervalo de timpo debe estar entre 1 minuto y 10 horas
