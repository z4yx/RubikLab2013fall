from OpenGL.GL import *
from OpenGL.GLU import *
from OpenGL.GLUT import *
from cube_oper import *
import cube

rotate_y = -45.0
rotate_x = 15.0
rotate_z = -15.0

anim_running = False
anim_deg = 0.0
anim_delta = 0.0
anim_elements = None
anim_axis = None

pendingSteps = ""

class CUBE_FACES:
    UP=0
    DOWN=1
    LEFT=2
    RIGHT=3
    FRONT=4
    BACK=5

CUBE_COLORS = [(1.0,1.0,0.0),(1.0,1.0,1.0),(0.0,0.0,1.0),(0.0,1.0,0.0),(1.0,0.0,0.0),(1.0,0.6,0.0)]
COLOR_INSIDE = (0.0,0.0,0.0)

def init():
    glClearColor(0.6, 0.6, 0.6, 0.0)

    glLightfv(GL_LIGHT1, GL_AMBIENT, GLfloat_4(0.2, 0.2, 0.2, 1.0) );
    glLightfv(GL_LIGHT1, GL_DIFFUSE, GLfloat_4(.8, .8, .8, .8));
    glLightfv(GL_LIGHT1, GL_POSITION, GLfloat_4(0, 0, 3, 1) );
    glEnable(GL_LIGHT1);
    # glEnable(GL_LIGHTING)

    glClearDepth(1.0)                 # Enables Clearing Of The Depth Buffer
    glDepthFunc(GL_LESS)                # The Type Of Depth Test To Do
    glEnable(GL_DEPTH_TEST)             # Enables Depth Testing
    glShadeModel(GL_SMOOTH)             # Enables Smooth Color Shading

    glMatrixMode(GL_PROJECTION)
    glLoadIdentity()                    # Reset The Projection Matrix
                                        # Calculate The Aspect Ratio Of The Window
    gluPerspective(45.0, float(400)/float(400), 0.1, 100.0)

    glMatrixMode(GL_MODELVIEW)

    # gluOrtho2D(-1.0, 1.0, -1.0, 1.0)

cood2index = lambda x:(0 if x<0 else (2 if x>0 else 1))

def getColor(face, n, m):


    if face<0 or face>5:
        print "getColor: wrong face"
        return COLOR_INSIDE
    if n<0 or n>2 or m<0 or m>2:
        print "getColor: wrong index"
        return COLOR_INSIDE

    color_index = cube.getcolor(face, n, m)
    return CUBE_COLORS[color_index]

def drawCubeElement(x, y, z, rot_x, rot_y, rot_z):

    glPushMatrix()

    glTranslatef(x, y, z)
    glRotatef(rot_x, 1, 0, 0)
    glRotatef(rot_y, 0, 1, 0)
    glRotatef(rot_z, 0, 0, 1)

    glBegin(GL_QUADS)
    color = (getColor(CUBE_FACES.UP, 2-cood2index(z), cood2index(x)) if y>0 else COLOR_INSIDE)
    glColor3f(*color)
    glVertex3f(1.0, 1.0, -1.0)
    glVertex3f(-1.0, 1.0, -1.0)
    glVertex3f(-1.0, 1.0, 1.0)
    glVertex3f(1.0, 1.0, 1.0)

    color = (getColor(CUBE_FACES.DOWN, cood2index(z), cood2index(x)) if y<0 else COLOR_INSIDE)
    glColor3f(*color)
    glVertex3f(1.0, -1.0, 1.0)
    glVertex3f(-1.0, -1.0, 1.0)
    glVertex3f(-1.0, -1.0, -1.0)
    glVertex3f(1.0, -1.0, -1.0)

    color = (getColor(CUBE_FACES.FRONT, cood2index(y), cood2index(x)) if z>0 else COLOR_INSIDE)
    glColor3f(*color)
    glVertex3f(1.0, 1.0, 1.0)
    glVertex3f(1.0, -1.0, 1.0)
    glVertex3f(-1.0, -1.0, 1.0)
    glVertex3f(-1.0, 1.0, 1.0)

    color = (getColor(CUBE_FACES.BACK, cood2index(y), 2-cood2index(x)) if z<0 else COLOR_INSIDE)
    glColor3f(*color)
    glVertex3f(-1.0, 1.0, -1.0)
    glVertex3f(-1.0, -1.0, -1.0)
    glVertex3f(1.0, -1.0, -1.0)
    glVertex3f(1.0, 1.0, -1.0)

    color = (getColor(CUBE_FACES.LEFT, cood2index(y), cood2index(z)) if x<0 else COLOR_INSIDE)
    glColor3f(*color)
    glVertex3f(-1.0, 1.0, -1.0)
    glVertex3f(-1.0, -1.0, -1.0)
    glVertex3f(-1.0, -1.0, 1.0)
    glVertex3f(-1.0, 1.0, 1.0)

    color = (getColor(CUBE_FACES.RIGHT, cood2index(y), 2-cood2index(z)) if x>0 else COLOR_INSIDE)
    glColor3f(*color)
    glVertex3f(1.0, 1.0, -1.0)
    glVertex3f(1.0, 1.0, 1.0)
    glVertex3f(1.0, -1.0, 1.0)
    glVertex3f(1.0, -1.0, -1.0)

    glEnd()

    glLineWidth(2)
    glColor3f(*COLOR_INSIDE)

    glBegin(GL_LINE_STRIP)

    glVertex3f(1.0, 1.0, 1.0)
    glVertex3f(1.0, -1.0, 1.0)
    glVertex3f(-1.0, -1.0, 1.0)
    glVertex3f(-1.0, 1.0, 1.0)
    glVertex3f(1.0, 1.0, 1.0)

    glVertex3f(1.0, 1.0, -1.0)
    glVertex3f(1.0, -1.0, -1.0)
    glVertex3f(-1.0, -1.0, -1.0)
    glVertex3f(-1.0, 1.0, -1.0)
    glVertex3f(1.0, 1.0, -1.0)

    glEnd()

    glBegin(GL_LINES)

    glVertex3f(1.0, -1.0, 1.0)
    glVertex3f(1.0, -1.0, -1.0)
    glVertex3f(-1.0, 1.0, 1.0)
    glVertex3f(-1.0, 1.0, -1.0)
    glVertex3f(-1.0, -1.0, 1.0)
    glVertex3f(-1.0, -1.0, -1.0)

    glEnd()

    glPopMatrix()

    # glRotatef(-rot_z, 0, 0, 1)
    # glRotatef(-rot_y, 0, 1, 0)
    # glRotatef(-rot_x, 1, 0, 0)
    # glTranslatef(-x, -y, -z)

def fetchPendings():
    global pendingSteps
    if len(pendingSteps) > 0:
        startAnimation(pendingSteps[0])
        pendingSteps = pendingSteps[1:]


def animEnded():
    global cur_oper
    cube.rotate(cur_oper)

    fetchPendings()

def drawFunc():
    global rotate_y,rotate_x,rotate_z
    global anim_deg,anim_running,anim_delta,anim_axis,anim_elements

    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT)

    glLoadIdentity();
    glTranslatef(0.0, 0.0, -20)

    glRotatef(rotate_y, 0, 1, 0)
    glRotatef(rotate_x, 1, 0, 0)
    glRotatef(rotate_z, 0, 0, 1)

    # drawCubeElement(0, 0, 0, 0, 0, 0)
    for i in [-2, 0, 2]:
        for j in [-2, 0, 2]:
            for k in [-2, 0, 2]:
                # drawCubeElement(i, j, k, rotate_x, rotate_y, 0)
                if anim_running and anim_elements.contains(i, j, k):
                    glPushMatrix()
                    if anim_axis=='x':
                        glRotatef(anim_deg, 1, 0, 0)
                    elif anim_axis=='y':
                        glRotatef(anim_deg, 0, 1, 0)
                    elif anim_axis=='z':
                        glRotatef(anim_deg, 0, 0, 1)

                    drawCubeElement(i, j, k, 0, 0, 0)
                    glPopMatrix()
                else:
                    drawCubeElement(i, j, k, 0, 0, 0)
    
    glFlush()
    glutSwapBuffers()

    if anim_running:
        anim_deg += anim_delta
        if anim_deg > 90 or anim_deg < -90:
            anim_running = False
            animEnded();

def startAnimation(oper):
    global cur_oper
    global rotate_y,rotate_x,rotate_z
    global anim_deg,anim_running,anim_delta,anim_axis,anim_elements

    cur_oper = oper;
    anim_running = True
    anim_deg = 0.0
    (anim_elements,anim_axis,anim_delta) = Operations[oper]
    anim_delta *= 4

def keyPressed(*args):
    global pendingSteps
    global cur_oper
    global rotate_y,rotate_x,rotate_z
    global anim_deg,anim_running,anim_delta,anim_axis,anim_elements

    key = args[0]
    
    if key == '\033':   #ESC
        sys.exit()
    elif key == '+':
        cube.writestate()
    elif key == '0':
        cube.readstate()
    elif key == '1':
        steps = cube.step1();
        pendingSteps = steps
        fetchPendings()
    elif key == '2':
        steps = cube.step2();
        pendingSteps = steps
        fetchPendings()
    # elif args[0] == 'a':
    #     rotate_y -= 5.0
    # elif args[0] == 'd':
    #     rotate_y += 5.0
    # elif args[0] == 'w':
    #     rotate_x -= 5.0
    # elif args[0] == 's':
    #     rotate_x += 5.0
    else:
        if not (key in Operations):
            return
        startAnimation(key)
    # elif args[0] == GLUT_KEY_LEFT:
    #     rotate_y -= 5.0
    # elif args[0] == GLUT_KEY_RIGHT:
    #     rotate_y += 5.0
    # elif args[0] == GLUT_KEY_UP:
    #     rotate_x -= 5.0
    # elif args[0] == GLUT_KEY_DOWN:
    #     rotate_x += 5.0

glutInit()
glutInitDisplayMode(GLUT_RGBA|GLUT_DOUBLE|GLUT_DEPTH)
glutInitWindowSize(400, 400)
glutCreateWindow("Cube")

glutDisplayFunc(drawFunc)
glutIdleFunc(drawFunc)
glutKeyboardFunc(keyPressed)
init()
glutMainLoop()