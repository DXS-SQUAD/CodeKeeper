#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSettings>
#include <QTextBrowser>
#include <QtWidgets>
#include <QFileIconProvider>
#include <QFileSystemModel>

#include "qmarkdowntextedit/qmarkdowntextedit.h"
#include "settingswindow.h"

class CustomIconProvider : public QFileIconProvider {
public:
    QIcon icon(IconType type) const override
    {
        switch (type) {
        case QFileIconProvider::IconType::Computer:
            return QIcon(":/home_dir.png");
        case QFileIconProvider::IconType::Trashcan:
            return QIcon(":/trash.png");
        case QFileIconProvider::IconType::File:
            return QIcon(":/document.png");
        case QFileIconProvider::IconType::Folder:
            return QIcon(":/folder.png");
        default:
            return QFileIconProvider::icon(type);
        }
    }
};


class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    QSettings *globalSettings;
    bool isVisibleNotesList;

    QFont selectedFont;
    QString font_size;
    QString theme;
    QDir path;

    QFileSystemModel *notesDirModel;
    QFileSystemModel *noteFileModel;


    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void openSettingsWindow();
    void openFolder();

    void hideNotesList();
    void showPreview();
    void updateMDPreview();
    void setHeader();
    void createNote();
    void removeNote();
    void saveNote();
    void toViewMode();
    void createFolder();

    void loadTasks();
    void addNewTask();
    void removeTask();

    void on_listWidget_itemClicked(QListWidgetItem *item);
    void renameItemOnDoubleClick(QListWidget *listWidget, QListWidgetItem *item);
    void onNoteDoubleClicked();
    void updateTasksProgress(QTabWidget *tasksTab, QListWidget *incompleteTasks, QListWidget *inprocessTasks, QListWidget *completeTasks, QProgressBar *tasksProgress);
    void loadDocumentations(QDir path, QComboBox &comboBox);
    void openProject(QListWidget *listWidget, QListWidgetItem *item);

    void createProject();
    void removeProject();
    void loadProjects();

    void setH1();
    void setH2();
    void setH3();
    void setList();
    void setLink();
    void setBold();
    void setItalic();
    void setStrike();
    void setTask();

    void updateWindowTitle();

    void setFontPr1();
    
    QString getCurrentDateTimeString();

    void create_tasks_connection();
    void create_projects_connection();
    
private:
    QWidget *centralWidget;
    QVBoxLayout *mainLayout;
    QTabWidget *tabs;

    // ========================================================
    // main tab
    QLabel *mainTitle;
    QPushButton *syncDataBtn;
    QPushButton *openSettingsBtn;

    // ========================================================
    // notes tab
    QTreeView *notesList;
    CustomIconProvider *iconProvider;
    QMarkdownTextEdit *noteEdit;
    MarkdownHighlighter *highlighter;
    QTextBrowser *mdPreview;
    QLineEdit *noteName;
    QToolButton *menuButton;
    QLabel *noteNameLabel;

    QPushButton *setH1B;
    QPushButton *setH2B;
    QPushButton *setH3B;
    QPushButton *setListB;
    QPushButton *setLinkB;
    QPushButton *setBoldB;
    QPushButton *setItalicB;
    QPushButton *setStrikeB;
    QPushButton *setTaskB;

    // ========================================================
    // tasks tab
    QListWidget *incompleteTasks;
    QListWidget *inprocessTasks;
    QListWidget *completeTasks;

    QProgressBar *tasksProgress;
    QToolButton *tasksMenuBtn;

    QLabel *label_1;
    QLabel *label_2;
    QLabel *label_3;

    QLineEdit *taskText;


    // ========================================================
    // projects tab
    QLabel *projectsMainLabel;
    QToolButton *projectsMenuButton;
    QMenu *projectsMenu;

    QLabel *fProjects;
    QLabel *flProjects;
    QLabel *sProjects;
    QLabel *nsProjects;

    QListWidget *notStartedProjects;
    QListWidget *startedProjects;
    QListWidget *finishedProjects;
    QListWidget *finishlineProjects;

    QAction *newNote;
    QAction *rmNote;
    QAction *newFolder;
    QAction *showList;
    QAction *showRender;
    QAction *addTask;
    QAction *rmTask;
    QAction *viewMode;
    QAction *newProject;
    QAction *rmProject;
    QAction *setH1A;
    QAction *setH2A;
    QAction *setH3A;
    QAction *setListA;
    QAction *setLinkA;
    QAction *setTaskA;
    QAction *setBoldA;
    QAction *setItalicA;
    QAction *setStrikeA;

    SettingsWindow *settingsWindow;
};
#endif  // MAINWINDOW_H
