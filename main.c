#include<gtk/gtk.h>

static void load_css(void){
  
  GtkCssProvider *provider;

  provider = gtk_css_provider_new();

  gtk_css_provider_load_from_path(
    provider,
    "style.css"
  );

  gtk_style_context_add_provider_for_display(
    gdk_display_get_default(),
    GTK_STYLE_PROVIDER(provider),
    GTK_STYLE_PROVIDER_PRIORITY_APPLICATION
  );

}

static void power_clicked(GtkButton *button, gpointer user_data)
{
    g_spawn_command_line_async("systemctl poweroff", NULL);
}

static void reboot_clicked(GtkButton *button, gpointer user_data)
{
    g_spawn_command_line_async("systemctl reboot", NULL);
}

static void logout_clicked(GtkButton *button, gpointer user_data)
{
    g_spawn_command_line_async("hyprctl dispatch exit", NULL);
}

static void activate(GtkApplication *app){
  GtkWidget *window;
  GtkWidget *powerbutton;
  GtkWidget *sleepbutton;
  GtkWidget *rebootbutton;
  GtkWidget *box;
  GtkWidget *powericon;
  GtkWidget *sleepicon;
  GtkWidget *rebooticon;

  window = gtk_application_window_new(app);
  gtk_window_set_title(GTK_WINDOW(window),"powerctl");
  gtk_window_set_default_size(GTK_WINDOW(window), 600,300);

  powericon = gtk_image_new_from_file("icons/power.svg");
  gtk_image_set_pixel_size(GTK_IMAGE(powericon), 80);

  sleepicon = gtk_image_new_from_file("icons/sleep.svg");
  gtk_image_set_pixel_size(GTK_IMAGE(sleepicon), 80);

  rebooticon = gtk_image_new_from_file("icons/reboot.svg");
  gtk_image_set_pixel_size(GTK_IMAGE(rebooticon), 80);

  box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 20);
  gtk_widget_set_halign(box, GTK_ALIGN_CENTER);
  gtk_widget_set_valign(box, GTK_ALIGN_CENTER);

  powerbutton = gtk_button_new();
  gtk_widget_set_size_request(powerbutton,80,80);
  gtk_button_set_child(GTK_BUTTON(powerbutton),powericon);

  sleepbutton = gtk_button_new();
  gtk_widget_set_size_request(sleepbutton,80,80);
  gtk_button_set_child(GTK_BUTTON(sleepbutton), sleepicon);

  rebootbutton = gtk_button_new();
  gtk_widget_set_size_request(rebootbutton,80,80);
  gtk_button_set_child(GTK_BUTTON(rebootbutton), rebooticon);

  g_signal_connect(powerbutton, "clicked", G_CALLBACK(power_clicked), NULL);
  g_signal_connect(rebootbutton, "clicked", G_CALLBACK(reboot_clicked), NULL);
  g_signal_connect(sleepbutton, "clicked", G_CALLBACK(logout_clicked), NULL);

  gtk_box_append(GTK_BOX(box), powerbutton);
  gtk_box_append(GTK_BOX(box), sleepbutton);
  gtk_box_append(GTK_BOX(box), rebootbutton);

  gtk_window_set_child(
    GTK_WINDOW(window),
    box
  );

  gtk_window_present(GTK_WINDOW(window));
  load_css();
}


int main(int argc,char **argv){
  
  GtkApplication *app;
  int status;

  app = gtk_application_new(
    "com.saksham.powerctl",
    G_APPLICATION_DEFAULT_FLAGS
  );

  g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);

  status = g_application_run(
    G_APPLICATION(app),
    argc,
    argv
  );

  g_object_unref(app);

  return status;

}
