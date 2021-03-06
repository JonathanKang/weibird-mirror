/*
 *  Weibird - view and compose weibo
 *  copyright (c) 2018-2019 jonathan kang <jonathankang@gnome.org>.
 *
 *  this program is free software: you can redistribute it and/or modify
 *  it under the terms of the gnu general public license as published by
 *  the free software foundation, either version 3 of the license, or
 *  (at your option) any later version.
 *
 *  this program is distributed in the hope that it will be useful,
 *  but without any warranty; without even the implied warranty of
 *  merchantability or fitness for a particular purpose.  see the
 *  gnu general public license for more details.
 *
 *  you should have received a copy of the gnu general public license
 *  along with this program.  if not, see <http://www.gnu.org/licenses/>.
 */

#include "wb-headerbar.h"

struct _WbHeaderbar
{
    /*< private >*/
    GtkHeaderBar parent_instance;
};

typedef struct
{
    GtkWidget *pri_menu;
} WbHeaderbarPrivate;

G_DEFINE_TYPE_WITH_PRIVATE (WbHeaderbar, wb_headerbar, GTK_TYPE_HEADER_BAR)

static void
wb_headerbar_init (WbHeaderbar *headerbar)
{
    gtk_widget_init_template (GTK_WIDGET (headerbar));
}

static void
wb_headerbar_class_init (WbHeaderbarClass *klass)
{
    GtkWidgetClass *widget_class;

    widget_class = GTK_WIDGET_CLASS (klass);

    gtk_widget_class_set_template_from_resource (widget_class,
                                                 "/com/jonathankang/Weibird/wb-headerbar.ui");
    gtk_widget_class_bind_template_child_private (widget_class,
                                                  WbHeaderbar, pri_menu);
}

WbHeaderbar *
wb_headerbar_new (void)
{
    return g_object_new (WB_TYPE_HEADERBAR, NULL);
}
