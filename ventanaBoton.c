#include <gtk/gtk.h>

//Imprimir mensaje al oprimir el boton
void mensaje(GtkWidget *widget, gpointer data){
	g_print ("Adios :)\n");
}

//Manejador para evitar que la ventana se cierre a menos que se use el boton
// Para que se cierre al usar este evento se cambia de 'TRUE' a 'FALSE'
gint delete_event (GtkWidget *widget, GdkEvent *event, gpointer data){
	g_print ("Usa el boton para cerrar\n");
	return TRUE;
}

//Terminar el programa por completo
void destroy (GtkWidget *widget, gpointer data){
	gtk_main_quit ();
}

int main(int argc, char *argv[]){
	GtkWidget *window;   //Se define un elemento visual: GtkWidget
	GtkWidget *button;   //Se define el boton
 	
	gtk_init(&argc, &argv);                       //Se inicializa con el contexto de la línea de comando
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL); //Se crea la ventana a visualizar
	gtk_window_set_default_size(GTK_WINDOW(window), 400, 200);   //Tamaño de la ventana

	//Conectar las señales a sus funciones correspondientes 
	g_signal_connect(G_OBJECT(window), "delete_event", G_CALLBACK(delete_event), NULL); 
	g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(destroy), NULL);

	gtk_container_set_border_width (GTK_CONTAINER (window), 10);  //Establecer el borde del boton

	button = gtk_button_new_with_label ("ATA");   //Etiqueta que contendra el boton

	g_signal_connect(G_OBJECT (button), "clicked", G_CALLBACK (mensaje), NULL);  //Desplegar nuestro mensaje al hacer click
	g_signal_connect_swapped(G_OBJECT (button), "clicked", G_CALLBACK(gtk_widget_destroy), G_OBJECT(window));   //Terminar el programa al hacer click

	gtk_container_add(GTK_CONTAINER (window), button);   //Agregar el boton a nuestra ventana

	gtk_widget_show (button);   //Se muestra el boton
	gtk_widget_show (window);   //Se muestra la ventana
	gtk_main();                 //Se invoca el método main que procesa los eventos
	return 0;
}
