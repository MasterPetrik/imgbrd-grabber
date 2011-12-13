#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>
#include "sourceswindow.h"
#include "batchwindow.h"
#include "QAffiche.h"
#include "QBouton.h"
#include "textedit.h"
#include "searchtab.h"



namespace Ui
{
    class mainWindow;
}

class mainWindow : public QMainWindow
{
    Q_OBJECT

	public:
		explicit mainWindow(QString, QStringList, QStringMap);
		~mainWindow();

	public slots:
		// Log
		void logShow();
		void logClear();
		// Menus
		void options();
		void optionsClosed();
		void aboutAuthor();
		void saveFolder();
		void blacklistFix();
		void emptyDirsFix();
		// Language
		void switchTranslator(QTranslator&, const QString&);
		void loadLanguage(const QString&, bool shutup = false);
		void changeEvent(QEvent*);
		// Favorites
		void loadFavorite(int);
		void favoriteProperties(int);
		void updateFavorites();
		void viewed();
		void setFavoriteViewed(QString);
		void favoritesBack();
		void checkFavorites();
		void loadNextFavorite();
		// Download
		void web(QString tags = "");
		void finishedLoading(Page*);
		void finishedLoadingPreview(Image*);
		void webZoom(int);
		// Batch download management
		void batchClear();
		void batchClearSel();
		void batchSel();
		void batchChange(int);
		void updateBatchGroups(int, int);
		void addGroup();
		void addUnique();
		void batchAddGroup(const QStringList& values);
		void batchAddUnique(QMap<QString,QString>);
		// Batch download
		void getAll(bool all = true);
		void getAllFinishedLoading(Page*);
		void getAllPerformTags(Image*);
		void getAllPerformImage();
		void getAllProgress(qint64, qint64);
		void getAllCancel();
		void _getAll();
		// Others
		void closeEvent(QCloseEvent*);
		void advanced();
		void saveAdvanced(sourcesWindow*);
		void init();
		// Tabs
		void addTab(QString tag = "");
		void addTabFavorite(int);
		void updateTabTitle(searchTab*);
		void closeCurrentTab();

	private:
		Ui::mainWindow		*ui;
		int					m_pagemax, m_timezonedecay, m_getAllId, m_getAllDownloaded, m_getAllExists, m_getAllIgnored, m_getAllErrors, m_getAllCount, m_getAllPageCount, m_getAllBeforeId, m_remainingPics, m_remainingSites, m_countPics, m_currentFav, m_currentFavCount;
		bool				m_allow, m_must_get_tags, m_loaded, m_getAllRequestExists, m_getAll;
		QSettings			*m_settings;
		QProcess			*m_process;
		QNetworkReply		*m_getAllRequest;
		batchWindow			*m_progressdialog;
		QString				m_program, m_currLang, m_currentFavorite;
		QStringList			m_tags, m_assoc, m_gotMd5;
		QTranslator			m_translator;
		QTime				*m_downloadTime;
		QDateTime			m_serverDate, m_loadFavorite;
		QMap<QString,int>	m_countPage;
		QList<QStringList>	m_groupBatchs;
		QList<Image*>		m_getAllImages, m_images;
		QList<Page*>		m_getAllPages, m_pages;
		QList<QAffiche*>	m_favoritesCaptions;
		QList<QBouton*>		m_favoritesImages, m_mergeButtons, m_webPics;
		QList<searchTab*>	m_tabs;
		QList<bool>			m_selectedSources;
		QList<QLabel*>		m_webSites;
		QMap<QString,QString>					m_favorites, m_params;
		QMap<QString,QStringList>				m_getAllDetails;
		QMap<QString,QMap<QString,QString> >	m_sites;
		QList<QProgressBar*>					m_progressBars;
		QList<QNetworkReply*>					m_replies;
		QList<QMap<QString,QString> >			m_details, m_batchs;
};

#endif // MAINWINDOW_H