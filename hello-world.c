#include <gtk/gtk.h>

static void
print_hello (GtkWidget *widget, gpointer data)
{
  g_print ("Hello World\n");
}

int
main (int argc, char *argv[])
{
  GtkWidget *window;
  GtkWidget *button;

  gtk_init (&argc, &argv);

  window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (window), "Hello World");
  gtk_window_set_default_size (GTK_WINDOW (window), 200, 100);
  gtk_window_set_position (GTK_WINDOW (window), GTK_WIN_POS_CENTER);

  button = gtk_button_new_with_label ("Hello World");
  g_signal_connect (button, "clicked", G_CALLBACK (print_hello), NULL);
  gtk_container_add (GTK_CONTAINER (window), button);

  gtk_widget_show_all (window);
  gtk_main ();

  return 0;
}