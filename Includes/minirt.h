/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdescour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:49:40 by cdescour          #+#    #+#             */
/*   Updated: 2023/03/21 23:08:07 by lreille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <unistd.h>
# include <stdbool.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <math.h>
# include <float.h>
# include "mlx.h"

# include "../Libft/libft.h"
# define AMB 1
# define CAM 2
# define LIG 3
# define SPH 4
# define PLA 5
# define CYL 6

# define RX 1920
# define RY 1080

//E1->argcheck an objects
# define E1001 "Error\nNot enough arguments\n"
# define E1002 "Error\nToo many arguments\n"
# define E1003 "Error\nFile name not defined\n"
# define E1004 "Error\nFile can not be found\n"
# define E1005 "Error\nCamera isn't found...\n"
# define E1006 "Error\nMust only have one camera\n"
# define E1007 "Error\nMust only have one ambiant light\n"
# define E1008 "Error\nMust only have one Light\n"
# define E1009 "Error\nWrong line in file\n"
# define E1010 "Error\nLine can't start with a number\n"

# define A1001 "Error\nWrong amount of arg for A\n"
# define A1002 "Error\nWrong lum ratio input for amb\n"
# define A1003 "Error\nWrong color input for amb\n"
# define A1004 "Error\nWrong amount of amb element\n"

# define L1001 "Error\nWrong amount of arg for L\n"
# define L1002 "Error\nWrong coord input for L\n"
# define L1003 "Error\nWrong lum ratio input for L\n"

# define C1001 "Error\nWrong amount of arg for C\n"
# define C1002 "Error\nWrong coord input for C\n"
# define C1003 "Error\nWrong orientation vector input for C\n"
# define C1004 "Error\nWrong FOV range input for C\n"

# define SP1001 "Error\nWrong amount of arg for sphere\n"
# define SP1002 "Error\nWrong coord input for sphere\n"
# define SP1003 "Error\nWrong diameter input for sphere\n"
# define SP1004 "Error\nWrong color input for sphere\n"

# define PL1001 "Error\nWrong amount of arg for plan\n"
# define PL1002 "Error\nWrong coord input for plan\n"
# define PL1003 "Error\nWrong orientation vector input for plan\n"
# define PL1004 "Error\nWrong color input for plan\n"

# define CY1001 "Error\nWrong amount of arg for cyl\n"
# define CY1002 "Error\nWrong coord input for cyl\n"
# define CY1003 "Error\nWrong orientation vector input for cyl\n"
# define CY1004 "Error\nWrong diameter input for cyl\n"
# define CY1005 "Error\nWrong height input for cyl\n"
# define CY1006 "Error\nWrong color input for cyl\n"

typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
}				t_vector;

typedef struct s_varcal
{
	double		a;
	double		b;
	double		c;
	double		delta;
	double		u;
	double		v;
	double		t;
	double		t1;
	double		t2;
	t_vector	edge1;
	t_vector	edge2;
	t_vector	oc;
}				t_varcal;

typedef struct s_camera
{
	t_vector		pos;
	t_vector		ort_vec;
	double			fov;
	t_vector		pixel;
	t_vector		n;
	t_vector		u;
	t_vector		v;
	t_vector		l;
	t_vector		r_dir;
	t_vector		translation;
	t_vector		rotation;
	struct s_camera	*previous;
	struct s_camera	*next;
}				t_camera;

typedef struct s_color
{
	double	r;
	double	g;
	double	b;
}				t_color;

typedef struct s_info
{
	char	**pos;
	char	**pos1;
	char	**pos2;
	char	**color;
	char	**vector;
	double	radius;
	double	height;
	char	**translation;
	char	**rotation;
	double	fov;
	double	int_light;
}				t_info;

typedef struct s_objet
{
	int				data;
	t_vector		pos;
	t_vector		pos1;
	t_vector		pos2;
	double			radius;
	t_color			color;
	t_vector		point;
	t_vector		normal;
	t_vector		v;
	t_vector		reflection;
	t_vector		light;
	t_vector		view;
	t_vector		translation;
	t_vector		rotation;
	double			height;
	double			t;
	double			test;
	int				i;
	struct s_objet	*previous;
	struct s_objet	*next;
}				t_objet;

typedef struct s_shadow
{
	double	degre;
	double	intersect;
}				t_shadow;

typedef struct s_tools
{
	int		index;
	int		data;
	int		intersect;
	int		bmp;
	int		tran_rot;
}				t_tools;

typedef struct s_parsing
{
	int	check;
	int	indice;
	int	error;
	int	r;
	int	a;
	int	c;
}				t_parsing;

typedef struct s_ray
{
	t_vector	origin;
	double		lenght;
	t_vector	direction;
}				t_ray;

typedef struct s_light
{
	t_vector		pos;
	t_color			rgb_light;
	double			int_light;
	t_vector		translation;
	struct s_light	*previous;
	struct s_light	*next;
}				t_light;

typedef struct s_ambient
{
	t_color		rgb_amb;
	double		int_amb;
}				t_ambient;

typedef struct s_render
{
	t_color	diffuse;
	t_color	specular;
	t_color	ambiant;
}				t_render;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	int		*img_data;
	int		size_line;
	int		bpp;
	int		*tab;
}				t_mlx;

typedef struct s_resolution
{
	int		x;
	int		y;
	int		width;
	int		height;
	double	half_height;
	double	half_width;
}				t_resolution;

typedef struct s_item
{
	t_vector		vector;
	t_objet			*objet;
	t_tools			tool;
	t_ray			ray;
	t_color			color;
	t_mlx			mlx;
	t_light			*light;
	t_ambient		ambient;
	t_camera		*camera;
	t_resolution	rsl;
	t_render		render;
	t_parsing		parsing;
	t_shadow		shad;
	int				nb_cam;
	int				nb_amb;
	int				nb_spt;
}				t_item;

t_color		ft_color(t_item *data);
double		vector_length(t_vector v);
//amb.c

t_color		render(t_item *data, t_color shadow);
int			ft_key_press(int keycode, t_item *data);
//cam.c
void		half_w_h(t_item *data);
void		calcul_pixel(t_item *data);
void		mapper_pixel(t_item *data);
void		camera_setting(t_item *data);
void		ray(t_item *data);

//check_obj.c
int			check_element(t_item *data, char **tab, int check);
void		ft_input(t_item *data, int indice, char *str);
void		check_data(t_item *data, char **tab);

//check_obj_error.c

void		ft_error(t_item *data, char *str);
//color.c
t_color		color_create(t_color v1);
t_color		color_add(t_color v1, t_color v2);
t_color		color_scal(double nb, t_color rgb);
t_color		color_prd(t_color col1, t_color col2);
t_color		min_max(t_color rgb);
t_color		make_number(double nb);

//ft_min_vec.c
void		sphere_p_n(t_item *data);
void		plane_p_n(t_item *data);
void		cylinder_p_n(t_item *data);
void		calcul_delta_cy(t_objet *objet, t_ray *ray, t_varcal *var);

//ft_check_data1.c
int			check_double(char *str);
int			check_rotation(char *parc);
int			check_rgb(char *parc);
int			check_pos(char *parc);
int			check_vec_ort(char *parc);

//ft_data_utils1.c
double		hit_sphere(t_objet *data, t_ray *ray);
double		hit_plane(t_objet *objet, t_ray *ray);
double		hit_cylinder(t_objet *objet, t_ray *ray);

//ft_data_utils2.c
void		just_calcul(t_item *data);
double		object_sp_cy(t_item *data, t_objet *tmp, t_ray *shade);
void		hit_objet2(t_item *data, t_ray *shade, t_objet *tmp);
void		hit_objet(t_item *data, double *t1);

//ft_elem_cap_check.c
int			ft_check_a(t_item *data, char **tab);
int			ft_check_l(t_item *data, char **tab);
int			ft_check_c(t_item *data, char **tab);

//ft_elem_cap_input.c
void		ft_a_input(t_item *data, char *str);
void		ft_c_input(t_item *data, char *str);
void		ft_l_input(t_item *data, char *str);

//ft_elem_cap_inputbis.c
t_light		*add_light(t_item *data, t_info object);
t_camera	*add_camera(t_item *data, t_info object);

//ft_elem_min_check.c
int			ft_check_sp(t_item *data, char **tab);
int			ft_check_pl(t_item *data, char **tab);
int			ft_check_cy(t_item *data, char **tab);

//ft_elem_min_input.c
void		ft_sp_input(t_item *data, char *str);
void		ft_pl_input(t_item *data, char *str);
void		ft_cy_input(t_item *data, char *str);

//ft_elem_min_inputbis.c
void		trans_rot(t_item *data, t_objet *new_object, t_info object);
t_objet		*add_sphere(t_item *data, t_info object);
t_objet		*add_plane(t_item *data, t_info object);
t_objet		*add_cylinder(t_item *data, t_info object);

//ft_mlx.c
void		ft_mlx1(t_item *data);
void		ft_mlx2(t_item *data);

//ft_splitbis.c
char		**ft_space_split(char const *s);

//ft_utils1.c
double		ft_atod(const char *str);
int			ft_dbltablen(char **tab);
int			check_num(char *str);
int			ft_close(t_item *data);

//ft_utils2.c
t_color		r_g_b(char *r, char *g, char *b);
t_vector	x_y_z(char *x, char *y, char *z);
int			free_exit(t_item *data);

//ft_utils3.c
void		witch_object(t_objet *objet, t_ray *ray, double *cross);
t_color		make_rrange(int rgb);
double		max(double a, double b);
double		min(double a, double b);
int			merge(t_color *data);

//get_next_line.c
int			free_leak(char *ptr, int nb, int fd);
char		*ft_check(char **tmp, int r, int fd);
int			ft_fill(char **tmp, int fd, char **line);
int			get_next_line(int fd, char **line);

//get_next_line_utils.c
size_t		ft_strlen(const char *str);
char		*ft_strjoin_free(char *s1, char const *s2);
char		*ft_substr(const char *s, unsigned int start, size_t len);
char		*ft_strchr(const char *s, int c);
char		*ft_strdup(const char *s1);

//parse_file.c
void		ft_check_input(t_item *data, char *line);
char		*ft_check_file(const char *s1, const char *s2);
void		read_line(t_item *data, int fd);
void		parsing(t_item *data, char **argv, int argc);

//rotation.c
t_vector	convert_to_radian(t_vector angle);
t_vector	rot_vector(t_vector vect_ort, t_vector angle);

//spot.c
t_color		shadows(t_item *data, t_objet *tmp);
void		ft_init_resolution(t_item *data);

//vector_utils1.c
double		vector_lenght(t_vector v);
t_vector	unit_vector(t_vector v);
t_vector	vector_cross(t_vector v1, t_vector v2);
t_color		make_range(t_color rgb);
t_vector	make_pos(double x, double y, double z);

//vector_utils2.c
double		vector_dot(t_vector v1, t_vector v2);
t_vector	vector_sub(t_vector v1, t_vector v2);
t_vector	vector_scal(double c, t_vector v);
t_vector	vector_add(t_vector v1, t_vector v2);
t_vector	vector_prd(t_vector v1, t_vector v2);

#endif
