#include "git_rev_parse.h"

#include <QProcess>
#include <QDebug>



/*******************************************************************
	GitStatus
********************************************************************/
GitRevParse::GitRevParse()
{}


/*******************************************************************
	GitStatus
********************************************************************/
GitRevParse::~GitRevParse()
{}



/*******************************************************************
	get_root_path
********************************************************************/
QString		GitRevParse::get_root_path( QString path )
{
	QProcess		*proc	=	new QProcess();
	QStringList		args;

	args << "rev-parse" << "--show-toplevel";

	proc->setWorkingDirectory(path);
	proc->start( "git", args );

	bool		result	=	proc->waitForFinished();
	QString		root_path;

	if( result )
	{
		root_path	=	proc->readAll();

		while( root_path.contains("\n") )
			root_path.replace( "\n", "" );
	}
	else
		root_path	=	QString("");

	delete	proc;
	return	root_path;
}
